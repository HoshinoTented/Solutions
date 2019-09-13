#include <utility>

//
// Created by hoshino on 18-8-26.
//

#ifndef LUOGU_1322_H
#define LUOGU_1322_H

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#define LIST_START '['
#define LIST_END ']'
#define SPACE ' '

namespace LuoGu {
	namespace P1322 {
		class Command {
		public:
			typedef int value_type;

			virtual auto eval(value_type &value) const -> void {}
		};

		class List : public Command {
		private:
			const std::vector<Command*> commands;
		public:
			explicit List(std::vector<Command *> commands) : commands(std::move(commands)) { }
			~List() {
//				for (auto command_ptr : commands) {
//					delete command_ptr;
//				}
			}

			auto eval(value_type &value) const -> void override {
				for (auto command : commands) {
					command->eval(value);
				}
			}
		};

		class Forward : public Command {
		private:
			const value_type step;
		public:
			static const std::string NAME;

			explicit Forward(const value_type &v) : step(v) {}

			auto eval(value_type &value) const -> void override {
				value += step;
			}
		};

		class Back : public Command {
		private:
			const value_type step;
		public:
			static const std::string NAME;

			explicit Back(const value_type &v) : step(v) {}

			auto eval(value_type &value) const -> void override {
				value -= step;
			}
		};

		class Repeat : public Command {
		private:
			const value_type times;
			const List commands;
		public:
			static const std::string NAME;

			explicit Repeat(const value_type &times, const List &list) : times(times), commands(list) {}

			auto eval(value_type &value) const -> void override {
				for (int i = 0; i < times; ++i) {
					commands.eval(value);
				}
			}
		};

		const std::string Forward::NAME = "FD";
		const std::string Back::NAME = "BK";
		const std::string Repeat::NAME = "REPEAT";

		class Parser {
		private:
			const std::string source;
			std::string::const_iterator it;

			auto currentChar() -> char {
				return *it;
			}

			auto next() -> void {
				++it;
			}

			auto nextNotClear() -> void {
				do {
					next();
				} while (currentChar() == SPACE);
			}

			// 当调用完这个函数 it将指向 `空格`
			auto read_full_string() -> std::string {
				std::string str;
				while (currentChar() != SPACE) {
					str.push_back(currentChar());
					next();
				}

				return str;
			}

			// 当调用完这个函数 it将指向 `数字之后的字符`
			auto read_full_number() -> Command::value_type {
				std::stringstream stream;
				while ('0' <= currentChar() && currentChar() <= '9') {
					stream << currentChar();
					next();
				}

				int i;
				stream >> i;
				return i;
			}

		public:
			explicit Parser(const std::string &s) : source("[" + s + "]"), it(source.begin()) { }

			auto start_parse() -> const List {
				if (currentChar() == LIST_START) {
					nextNotClear();

					std::vector<Command*> commands;

					while (currentChar() != LIST_END) {
						std::string command = read_full_string();
						nextNotClear();
						Command::value_type arg = read_full_number();
						if (command == Forward::NAME) {
							commands.push_back(new Forward(arg));
						} else if (command == Back::NAME) {
							commands.push_back(new Back(arg));
						} else if (command == Repeat::NAME) {
							auto list = start_parse();
							commands.push_back(new Repeat(arg, list));
						} else throw "Unknown command";

						if (currentChar() == SPACE) nextNotClear();
					}

					nextNotClear();
					return List(commands);
				} else throw "Excepted LINE_START";
			}
		};
	}
}

auto main(int argc, char *argv[]) -> int {
	char *commands = new char[255];
	LuoGu::P1322::Command::value_type i = 0;
	std::cin.getline(commands, 255);
	LuoGu::P1322::Parser(std::string(commands)).start_parse().eval(i);
	std::cout << std::abs(i) << std::endl;

	return 0;
}

#endif //LUOGU_1322_H
