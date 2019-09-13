//
// Created by hoshino on 18-10-31.
//

#ifndef LUOGU_P1087_HPP
#define LUOGU_P1087_HPP

#include <bits/stdc++.h>

struct Node {
	enum Type {
		F, B, I
	};

	Type type;
	Node *l, *r;

	Node(const Type &t, Node *l, Node *r) : type(t), l(l), r(r) {}

	auto typeChar() const -> char {
		switch (type) {
			case F:
				return 'F';
			case B:
				return 'B';
			case I:
				return 'I';
			default:
				throw "Unknown";
		}
	}
};

auto fbi(const Node::Type &t0, const Node::Type &t1) -> Node::Type {
	return t0 != t1 ? Node::Type::F : t0;
}

auto fbi(const char &c) -> Node * {
	Node::Type t = c == '0' ? Node::Type::B : Node::Type::I;

	return new Node{t, nullptr, nullptr};
}

auto fbi(const std::string &str, const size_t &begin, const size_t &end) -> Node * {
	Node *node;

	if (end - begin != 1) {
		size_t mid = (begin + end) / 2;

		Node *l = fbi(str, begin, mid);
		Node *r = fbi(str, mid, end);

		node = new Node{fbi(l->type, r->type), l, r};
	} else node = fbi(str[begin]);

	std::cout << node->typeChar();

	return node;
}

auto main(int, char **) -> int {
	int unused;
	std::string input;
	std::cin >> unused >> input;

	fbi(input, 0, input.size());

	return 0;
}

#endif //LUOGU_P1087_HPP
