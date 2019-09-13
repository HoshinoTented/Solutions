//
// Created by hoshino on 18-8-21.
// TODO TLE

#ifndef LUOGU_4008_H
#define LUOGU_4008_H

#include <iostream>
#include <string>

#define self (*this)
#define INSERT_MAX (2 * 1024 * 1024)

class Editor {
public:
	typedef std::string::size_type pointer;

	Editor() : text(std::string("\0")), p(0) { }

	void insert(const std::string &text) {
		self.text.insert(self.p, text);
	}

	void remove(const unsigned int &count) {
		text.erase(p, count);
	}

	void move(const unsigned int &pointer) const {
		self.p = pointer;
	}

	std::string get(const unsigned int &count) const {
		std::string str;
		for (pointer i = 0; i < count; ++i) {
			str += self[p + i];
		}

		return str;
	}

	void prev() const {
		self.p --;
	}

	void next() const {
		self.p ++;
	}

	const char operator[](const pointer &p) const {
		return text[p];
	}

private:
	std::string text;
	mutable pointer p;
};

int main(int argc, char *argv[]) {
	unsigned int commandCount;
	std::cin >> commandCount;
	std::string command;

	Editor editor;

	unsigned int n;
	std::string s;

	for (unsigned int i = 0; i < commandCount; ++i) {
		std::cin >> command;

		if (command == "Insert") {
			std::cin >> n;
			char c[INSERT_MAX];
			while (s.length() != n) {
				std::cin.getline(c, INSERT_MAX);
				s.insert(s.length(), c);
			}

			editor.insert(s);
			s = std::string();
		} else if (command == "Move") {
			std::cin >> n;
			editor.move(n);
		} else if (command == "Delete") {
			std::cin >> n;
			editor.remove(n);
		} else if (command == "Get") {
			std::cin >> n;
			std::cout << editor.get(n) << std::endl;
		} else if (command == "Prev") {
			editor.prev();
		} else if (command == "Next") {
			editor.next();
		}
	}

	return 0;
}

#endif //LUOGU_4008_H
