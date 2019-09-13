//
// Created by hoshino on 18-12-22.
//

#ifndef LUOGU_SPLAY_HPP
#define LUOGU_SPLAY_HPP

#include <cassert>
#include <string>
#include <iostream>

using T = int;

struct Node {
	T value;
	Node *l, *r;

	auto to_string() -> std::string {
		auto lS = l ? l->to_string() : "NIL";
		auto rS = r ? r->to_string() : "NIL";

		return "(" + std::to_string(value) + " " + lS + " " + rS + ")";
	}
};

auto left_rotate(Node **node) -> void {
	Node *r = (*node)->r;
	(*node)->r = r->l;
	r->l = *node;
	*node = r;
}

auto right_rotate(Node **node) -> void {
	Node *l = (*node)->l;
	(*node)->l = l->r;
	l->r = *node;
	*node = l;
}

auto search(Node *root, const T &value, Node *_default, Node **output) -> bool {
	if (root == nullptr) {
		*output = _default;

		return false;
	}

	if (root->value == value) {
		*output = root;

		return true;
	}

	return search((value < root->value) ? root->l : root->r, value, root, output);
}

auto insert(Node *root, const T &value) -> bool {
	Node *input = nullptr;

	if (search(root, value, nullptr, &input)) {
		return false;
	}

	assert(input);

	Node *newNode = new Node{value, nullptr, nullptr};

	(value < input->value ? input->l : input->r) = newNode;

	return true;
}

auto search_with_splay(Node **root, const T &value) -> Node * {
	if ((*root) == nullptr) return nullptr;
	if ((*root)->value == value) return *root;

	if (value < (*root)->value) {
		search_with_splay(&(*root)->l, value);
		right_rotate(root);

	} else {
		search_with_splay(&(*root)->r, value);
		left_rotate(root);
	}

	return *root;
}

auto main(int, char **) -> int {
	srandom(static_cast<unsigned int>(time(nullptr)));

	constexpr int size = 10;
	int arr[size] = {7, 1, 2, 5, 9, 4, 8, 3, 6, 0};

	Node root{arr[0], nullptr, nullptr};
	Node *pRoot = &root;

	for (int i = 1; i < size; ++ i) {
		insert(pRoot, arr[i]);
	}

	std::cout << pRoot->to_string() << std::endl;

	for (int i = 0; i < 5; ++ i) {
		auto ix = random() % 10;

		std::cout << "Search: " << arr[ix] << std::endl;
		search_with_splay(&pRoot, arr[ix]);
		std::cout << "Tree: " << pRoot->to_string() << std::endl;
	}

	return 0;
}

#endif //LUOGU_SPLAY_HPP
