#include <utility>

#include <utility>

//
// Created by hoshino on 18-8-28.
//

#ifndef LUOGU_1449_H
#define LUOGU_1449_H


#include <sstream>
#include <iostream>
#include <stack>
#include <string>
#include <\
vec\
tor>
// ↑ 花里胡哨起来了

#define EON '.'		//end of number
#define EOL '@'		//end of line

namespace LuoGu {
	namespace P1449 {
		using value_type = int;

		class Lexer {
		private:
			std::string source;

			auto read_full_number(std::string::const_iterator &it) -> value_type {
				std::stringstream stream;
				while (*it != EON) {
					stream << *it++;
				}

				value_type v;
				stream >> v;
				return v;
			}

		public:
			struct Token {
				enum TokenType {
					NUM, PLUS, MINUS, TIMES, DIV
				};
				const TokenType type;
				value_type data;

				explicit Token(const TokenType &type, const value_type &data = 0) : type(type), data(data) {}
			};

			using tokens_type = std::vector<Token>;

			explicit Lexer(std::string source) : source(std::move(source)) {}

			auto startLex() -> tokens_type {
				tokens_type tokens;
				auto it = source.cbegin();

				while (*it != EOL) {
					if (isdigit(*it)) {
						tokens.push_back(Token(Token::NUM, read_full_number(it)));
					} else {
						switch (*it) {
							case '+':
								tokens.push_back(Token(Token::PLUS)); break;
							case '-':
								tokens.push_back(Token(Token::MINUS)); break;
							case '*':
								tokens.push_back(Token(Token::TIMES)); break;
							case '/':
								tokens.push_back(Token(Token::DIV)); break;
							default:
								throw "Unknown Command";
						}
					}

					++ it;
				}

				return tokens;
			}
		};
	}
}

using namespace LuoGu::P1449;

auto function(const Lexer::Token::TokenType &token) -> value_type (*)(const value_type &, const value_type &) {
	switch (token) {
		case Lexer::Token::PLUS: return [](const value_type &a, const value_type &b) { return a + b; };
		case Lexer::Token::MINUS: return [](const value_type &a, const value_type &b) { return a - b; };
		case Lexer::Token::TIMES: return [](const value_type &a, const value_type &b) { return a * b; };
		case Lexer::Token::DIV: return [](const value_type &a, const value_type &b) { return a / b; };
		default: throw "UnSupportOperator";
	}
}

auto eval(const Lexer::tokens_type &tokens) -> const value_type {
	std::stack<value_type> stack;
	auto it = tokens.cbegin();
	while (it != tokens.cend()) {
		if ((*it).type == Lexer::Token::NUM) {
			stack.push((*it).data);
		} else {
			value_type a = stack.top();
			stack.pop();
			value_type b = stack.top();
			stack.pop();
			auto f = function((*it).type);
			stack.push(f(b, a));
		}

		++ it;
	}

	return stack.top();
}

auto main(int argc, char *argv[]) -> int {
	std::string formula;
	std::cin >> formula;
	try {
		std::cout << eval(Lexer(formula).startLex()) << std::endl;
	} catch (char const* e) {
		std::cout << e << std::endl;
	}


	return 0;
}

#endif //LUOGU_1449_H
