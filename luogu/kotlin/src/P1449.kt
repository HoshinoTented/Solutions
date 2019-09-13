import java.util.Stack

object P1449 {
	const val SEPARATOR = '.'

	@JvmStatic
	fun main(args: Array<String>) {
		readLine()?.dropLast(1)?.let { formula ->
			Stack<Int>().let { s ->
				var it = 0
				fun current(): Char = formula[it]
				fun next() {
					++ it
				}

				fun readFullNumber(): Int = buildString {
					while (current() != SEPARATOR) {
						append(current())
						next()
					}
				}.toInt()

				while (it != formula.length) {
					when {
						current().isDigit() -> s.push(readFullNumber())
						else -> {
							val f: Int.(Int) -> Int = when (current()) {
								'+' -> Int::plus
								'-' -> Int::minus
								'*' -> Int::times
								'/' -> Int::div

								else -> TODO()
							}

							s.pop().let { a ->
								s.pop().f(a).run(s::push)
							}
						}
					}

					next()
				}

				println(s.peek())
			}
		}
	}
}