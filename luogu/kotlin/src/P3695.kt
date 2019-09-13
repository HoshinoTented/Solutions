@file:Suppress("MemberVisibilityCanBePrivate", "unused")

import java.lang.StringBuilder
import java.util.LinkedList

object P3695 {
	object Runtime {
		class NameSpace(val map : MutableMap<String, Any> = HashMap(), val parent : NameSpace? = null) : MutableMap<String, Any> by map
		class RuntimeArray(val range : IntRange) {
			val array = IntArray(range.last - range.first)

			operator fun get(index : Int) : Int {
				return array[index - range.first]
			}
		}
	}

	object AST {
		interface ASTNode {
			fun eval(ns : Runtime.NameSpace)
		}

		abstract class BaseASTNode : ASTNode {
			//NOP
		}

		data class ASTRootNode(val nodes : List<ASTNode>) : BaseASTNode() {
			override fun eval(ns : Runtime.NameSpace) {
				nodes.forEach { it.eval(ns) }
			}
		}

		abstract class Var : BaseASTNode() {
			abstract val symbol : String

			protected abstract fun init() : Any

			override fun eval(ns : Runtime.NameSpace) {
				if (ns.containsKey(symbol)) throw IllegalArgumentException(symbol)

				ns[symbol] = init()
			}
		}

		class IntVar(override val symbol : String) : Var() {
			override fun init() : Any = 0
		}

		class ArrayVar(override val symbol : String, val range : IntRange) : Var() {
			override fun init() : Any = Runtime.RuntimeArray(range)
		}

		class DefineVars(val vars : List<Var>) : BaseASTNode() {
			override fun eval(ns : Runtime.NameSpace) {
				vars.forEach {
					it.eval(ns)
				}
			}
		}
	}

	object Tokens {
		sealed class Token {
			object BlockBegin : Token()
			object BlockEnd : Token()
			object ArrayBegin : Token()
			object ArrayEnd : Token()
			object Colon : Token()    // :
			object Comma : Token()
			object Range : Token()    // ..
			object Comment : Token()    // #

			object Plus : Token()
			object Minus : Token()
			object Times : Token()
			object Div : Token()

			object Lt : Token()
			object Gt : Token()
			object Le : Token()
			object Ge : Token()
			object Eq : Token()
			object Neq : Token()

			data class Const(val value : Int) : Token()        // const number
			data class Symbol(val str : String) : Token()

			object EOL : Token()
			object Set : Token()
			object Dot : Token()
		}
	}

	object Lexer {
		/**
		 * ts : List<Tokens.Token> 应使用 LinkedList<Tokens.Token>, 需要在首部多次插入, 并且最后 Parse 是顺序遍历
		 */
		class Lexer(val source : String) {
			companion object {
				val symbol = 'a'..'z'
				val digit = '0'..'9'
				const val eol = '\n'
			}

			fun head(str : IntRange) : Char {
				return source[str.first]
			}

			fun tail(str : IntRange) : IntRange {
				return str.first + 1..str.last
			}

			fun destruct(str : IntRange) : Pair<Int, IntRange> {
				return str.first to tail(str)
			}

			fun next(str : IntRange) : IntRange {
				return str.first..str.last
			}

			tailrec fun nextNotEmpty(str : IntRange) : IntRange {
				return when (head(str)) {
					' ' -> nextNotEmpty(tail(str))
					else -> str
				}
			}

			fun readFull(range : IntRange, f : (Char) -> Boolean) : Pair<StringBuilder, IntRange> {
				if (range.first == range.last || ! f(head(range))) return StringBuilder() to range

				return readFull(tail(range), f).let { (str, source) ->
					str.append(head(range)) to source
				}
			}

			fun readFullSymbol(str : IntRange) = readFull(str) { c -> c in symbol }.let { (str, source) ->
				Tokens.Token.Symbol(str.reverse().toString()) to source
			}

			fun readFullNumber(str : IntRange) = readFull(str, Char::isDigit).let { (str, source) ->
				Tokens.Token.Const(str.reverse().toString().toInt()) to source
			}

			fun readFullComment(str : IntRange) = readFull(str) { c -> c != eol}.let { (_, source) ->
				Tokens.Token.Comment to source
			}

			fun lex(range : IntRange = 0..source.length) : LinkedList<Tokens.Token> {
				if (range.first == range.last) return LinkedList<Tokens.Token>().apply { push(Tokens.Token.EOL) }

				if (head(range) == ' ') return lex(nextNotEmpty(range))

				val (token, source) = when (val x = head(range)) {
					in symbol -> readFullSymbol(range)
					in digit -> readFullNumber(range)
					'#' -> readFullComment(tail(range))

					else -> when (x) {
						eol -> Tokens.Token.EOL
						'{' -> Tokens.Token.BlockBegin
						'}' -> Tokens.Token.BlockEnd
						'[' -> Tokens.Token.ArrayBegin
						']' -> Tokens.Token.ArrayEnd
						':' -> Tokens.Token.Colon
						',' -> Tokens.Token.Comma
						'.' -> Tokens.Token.Dot
						'+' -> Tokens.Token.Plus
						'-' -> Tokens.Token.Minus
						'*' -> Tokens.Token.Times
						'/' -> Tokens.Token.Div
						'<' -> Tokens.Token.Lt
						'>' -> Tokens.Token.Gt
						'=' -> Tokens.Token.Set

						else -> TODO(x.toString())
					} to tail(range)
				}

				return lex(source).also { ts ->
					val componentToken = when (token) {
						Tokens.Token.Set -> when (ts.first) {
							Tokens.Token.Lt -> Tokens.Token.Le
							Tokens.Token.Gt -> Tokens.Token.Ge
							Tokens.Token.Set -> Tokens.Token.Eq

							else -> null
						}

						Tokens.Token.Dot -> when (ts.first) {
							Tokens.Token.Dot -> Tokens.Token.Range

							else -> null
						}

						else -> null
					}

					if (componentToken != null) ts.pop()
					ts.push(componentToken ?: token)
				}
			}
		}
	}

	object Parser {
		class Parser(val tokens : List<Tokens.Token>) {
			fun nextNotEOL(it : Iterator<Tokens.Token>) : Tokens.Token {
				return it.next().let { token ->
					if (token is Tokens.Token.EOL) nextNotEOL(it) else token
				}
			}

			fun parse() : AST.ASTRootNode {
				return parseTokens().run(AST::ASTRootNode)
			}

			fun parseVars(it : Iterator<Tokens.Token>) : LinkedList<AST.Var> {
				if (it.hasNext().not()) return LinkedList()

				return it.next().let { symbol ->
					symbol as Tokens.Token.Symbol

					it.next() as Tokens.Token.Colon

					it.next().let { type ->
						type as Tokens.Token.Symbol

						when (type.str) {
							"int" -> AST.IntVar(symbol.str)
							"array" -> {
								it.next() as Tokens.Token.ArrayBegin
								it.next().let { begin ->
									begin as Tokens.Token.Const

									it.next() as Tokens.Token.Range

									it.next().let { end ->
										end as Tokens.Token.Const

										AST.ArrayVar(symbol.str, begin.value..end.value)
									}
								}
							}

							else -> TODO(type.str)
						}
					}
				}.run {
					nextNotEOL(it)

					parseVars(it).apply { add(this@run) }
				}
			}

			fun parseBlock(it : Iterator<Tokens.Token>) : AST.ASTNode {
				return it.next().let { token ->
					if (token !is Tokens.Token.Symbol) TODO()

					when (token.str) {
						"vars" -> AST.DefineVars(parseVars(it))
						"ihu" -> TODO()
						"hor" -> TODO()
						"while" -> TODO()

						else -> TODO()
					}
				}
			}

			fun parseTokens(it : Iterator<Tokens.Token> = tokens.iterator()) : LinkedList<AST.ASTNode> {
				if (it.hasNext().not()) return LinkedList()

				return it.next().let { token ->
					when (token) {
						Tokens.Token.Comment -> Unit	// Nothing to do
					}

					parseTokens()
				}
			}
		}
	}

	fun main() {

	}
}