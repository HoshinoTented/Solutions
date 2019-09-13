//
// Created by hoshino on 18-11-14.
//

#ifndef LUOGU_BINARY_SEARCH_TREE_HPP
#define LUOGU_BINARY_SEARCH_TREE_HPP

#include <bits/stdc++.h>
#include "utils/tree.cpp"

using T = int;
using tree = hoshino::tree<T>;

auto search(tree *root, const T &v, tree *parent, tree *&out) -> bool {
	if (! root) {
		out = parent;
		return false;
	} else if (root->value == v) {
		out = root;
		return true;
	} else return search(v < root->value ? root->l : root->r, v, root, out);
}

auto add(tree *root, const T &v) -> tree * {
	tree *in = nullptr;
	if (! search(root, v, nullptr, in)) {
		assert(in);
		tree *node = new tree(v, nullptr, nullptr);
		if (v < in->value) in->l = node;
		else in->r = node;

		return node;
	} else return in;
}

auto main(int, char **) -> int {
	constexpr size_t len = 9;
	int arr[len] = {
			67, 35, 12, 74, 25, 54, 46, 13, 24
	};

	tree root(arr[0], nullptr, nullptr);

	for (size_t i = 1; i < len; ++ i) add(&root, arr[i]);

	std::cout << root.to_string(std::to_string) << std::endl;

	tree *out = nullptr;
	search(&root, 13, nullptr, out);

	assert(out);
	std::cout << out->value << std::endl;

	return 0;
}

#endif //LUOGU_BINARY_SEARCH_TREE_HPP
