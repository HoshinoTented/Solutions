//
// Created by hoshino on 18-9-23.
//

#ifndef LUOGU_1022_HPP
#define LUOGU_1022_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace LuoGu {
	namespace P1022 {
		using number = int;

		struct Element {
			enum TokenType {
				PLUS, MINUS
			};

			TokenType type;
			number value;
			char unknown;

			Element(const TokenType &type, const number &value = 0, const char &unknown = '\0')
					: type(type),
					  value(value),
					  unknown(unknown) {}
		};

		class Lexer {
		public:
			using tokens_type = std::vector<Element>;

			explicit Lexer(std::string source) {
				auto eq = std::find(source.begin(), source.end(), '=');
				if (*source.begin() != '-') {
					source.insert(source.begin(), '+');
					++ eq;
				}

				if (std::isdigit(*(eq + 1))) source.insert(eq + 1, '+');

				this->source = source;
			}

			auto startLex() -> std::pair<tokens_type, tokens_type> {
				auto eq = std::find(source.begin(), source.end(), '=');
				return {startLex(source.begin(), eq), startLex(eq + 1, source.end())};
			}

		private:
			std::string source;
			using iterator = std::string::iterator;

			auto startLex(iterator begin, const iterator &end) -> tokens_type {
				tokens_type tokens;

				while (begin != end) {
					tokens.push_back(lexNumber(*begin ++ == '+' ? Element::PLUS : Element::MINUS, begin, end));
				}

				return tokens;
			}

			//要求 begin 指向数字的第一位(或负号), 调用之后 begin 指向数字之后的字符
			auto lexNumber(const Element::TokenType &type, iterator &begin, const iterator &end) -> Element {
				std::string number;
				if (*begin == '-') {
					number.push_back(*begin ++);
				}

				while (isdigit(*begin)) {
					number.push_back(*begin ++);
				}

				if (number.empty()) number = "1";
				int value = std::stoi(number);

				if (std::isalpha(*begin)) {
					return {type, value, *begin ++};
				} else return {type, value};
			}
		};

		auto fold(Lexer::tokens_type &formula) -> Element {
			auto it = formula.cbegin();
			Element element = *it;

			element.value *= element.type ? - 1 : 1;
			element.type = Element::PLUS;

			++ it;

			while (it != formula.cend()) {
				element.value += it->value * (it->type ? - 1 : 1);
				++ it;
			}

			return element;
		}

		auto moveElement(Lexer::tokens_type &self, Lexer::tokens_type &target, bool (*check)(const Element &)) -> void {
			for (auto it = self.begin(); it != self.end();) {
				if (check(*it)) {
					it->type = Element::TokenType(! it->type);
					target.push_back(*it);
					self.erase(it);
				} else ++ it;
			}
		}

		auto generalized(std::pair<Lexer::tokens_type, Lexer::tokens_type> &formula) -> std::pair<Element, Element> {
			auto left = formula.first, right = formula.second;

			moveElement(left, right, [](const Element &a) { return a.unknown == '\0'; });
			moveElement(right, left, [](const Element &a) { return a.unknown != '\0'; });

			return {fold(left), fold(right)};
		}
	}
}

using namespace LuoGu::P1022;

auto main(int, char **) -> int {
	std::string formula;
	std::cin >> formula;
	Lexer lexer(formula);
	auto bf = lexer.startLex();
	auto p = generalized(bf);

	printf("%c=%.3f\n", p.first.unknown, p.first.value == 0 ? 0.0 : (double) p.second.value / p.first.value);

	return 0;
}

#endif //LUOGU_1022_HPP
