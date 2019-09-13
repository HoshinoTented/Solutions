//
// Created by hoshino on 18-11-16.
//

#ifndef LUOGU_TREAP_HPP
#define LUOGU_TREAP_HPP

#include <bits/stdc++.h>

#define null nullptr

using T = int;

class treap_node {
public:
	using weight_type = long;
	T v;
	treap_node *parent, *leftChild, *rightChild;
	weight_type weight;

	treap_node(const T &v, const weight_type &weight, treap_node *p = null, treap_node *l = null, treap_node *r = null)
			: v(v), parent(p), leftChild(l), rightChild(r), weight(weight) {

	}

	auto to_string() -> std::string {
		auto lS = leftChild ? leftChild->to_string() : "null";
		auto rS = rightChild ? rightChild->to_string() : "null";
		return "(" + std::to_string(v) + " "
			   + std::to_string(weight) + " "
			   + lS + " "
			   + rS + ")";
	}
};

auto left_rotate(treap_node &parent) -> bool {
	treap_node *target = parent.parent;
	if (! target) return false;
//	if (parent->parent) {
//		(parent->parent->leftChild == parent ? parent->leftChild : parent->rightChild) = &target;
//	}
	std::swap(*target, parent);

	parent.rightChild = target->leftChild;
	target->leftChild = &parent;
	target->parent = parent.parent;
	parent.parent = target;

	return true;
}

auto right_rotate(treap_node &parent) -> bool {
	treap_node *target = parent.parent;
	if (! target) return false;
//	if (parent->parent) {
//		(parent->parent->leftChild == parent ? parent->leftChild : parent->rightChild) = &target;
//	}
	std::swap(*target, parent);

	parent.leftChild = target->rightChild;
	target->rightChild = &parent;
	target->parent = parent.parent;
	parent.parent = target;

	return true;
}

auto update(treap_node &target) -> void {
	auto isLeftChild = [&target] { return target.parent->leftChild == &target; };

	while (target.parent && target.parent->weight > target.weight) {
		(isLeftChild() ? right_rotate : left_rotate)(target);
	}
}

auto search(treap_node *root, const T &value, treap_node *def, treap_node *&output) -> bool {
	if (! root) {
		output = def;
		return false;
	} else if (root->v == value) {
		output = root;
		return true;
	}

	return value < root->v ? search(root->leftChild, value, root, output) : search(root->rightChild, value, root,
																				   output);
}

auto add(treap_node &root, const T &value, const treap_node::weight_type &weight = 0) -> bool {
	treap_node *output = nullptr;
	if (! search(&root, value, nullptr, output)) {
		assert(output);

		treap_node *node = new treap_node(value, weight ? weight : random(), output);

		(value < output->v ? output->leftChild : output->rightChild) = node;

		update(*node);

		return true;
	} else return false;
}

auto main(int, char **) -> int {
//#define DEBUG
#ifdef DEBUG
	treap_node root(5, 5);
	treap_node l(3, 1, &root);
	root.leftChild = &l;

	update(l);
#else
	srandom(static_cast<unsigned int>(time(NULL)));
	treap_node root(5, random());

	T values[] = {
			3, 6, 1, 7, 12, 8, 2, 4, 99, 100, 101
	};

	for (auto &v : values) {
		add(root, v);
	}

	std::cout << root.to_string() << std::endl;
#endif
	return 0;
}

#endif //LUOGU_TREAP_HPP
