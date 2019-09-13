//
// Created by hoshino on 18-11-10.
// WA

#ifndef LUOGU_U51945_HPP
#define LUOGU_U51945_HPP

#include <bits/stdc++.h>

using T = short;

struct Tree {
	T weight;
	Tree *l, *r, *p;

	explicit Tree() : Tree(0) {}

	explicit Tree(const T &weight, Tree *l = nullptr, Tree *r = nullptr, Tree *p = nullptr) : weight(weight), l(l),
																							  r(r), p(p) {}

	auto to_array() const -> std::list<T> & {
		if (! lazy) {
			auto *list = new std::list<T>();
			auto pushChild = [list](const Tree *child) {
				if (child) {
					auto lArr = child->to_array();
					list->insert(list->end(), lArr.begin(), lArr.end());
				} else list->push_back(- 1);
			};

			pushChild(l);
			list->push_back(weight);
			pushChild(r);

			lazy = list;
		}

		return *lazy;
	}

private:
	mutable std::list<T> *lazy = nullptr;
};

auto build() -> Tree * {
	int nodeC;
	std::cin >> nodeC;
	Tree *trees = new Tree[nodeC];        //do not free this
	for (int i = 0; i < nodeC; ++ i) {
		std::cin >> trees[i].weight;
	}

	for (int i = 0; i < nodeC; ++ i) {
		int lid, rid;
		std::cin >> lid >> rid;
		if (lid != - 1) {
			trees[i].l = trees + (lid - 1);
			trees[i].l->p = trees + 1;
		}

		if (rid != - 1) {
			trees[i].r = trees + (rid - 1);
			trees[i].r->p = trees + 1;
		}
	}

	for (int i = 0; i < nodeC; ++ i) {
		if (trees[i].weight != 0 && trees[i].p == nullptr) return trees + i;
	}

	throw std::runtime_error("No such root element");
}

auto reverseWithCompare(const std::list<T> &a, const std::list<T> &b) -> bool {
	if (a.size() != b.size()) return false;
	auto end = a.end();
	for (auto ia = a.begin(), ib = -- b.end(); ia != end; ++ ia, -- ib) if (*ia != *ib) return false;

	return true;
}

auto check(const Tree *_root) -> int {
	if (! _root) return - 1;
	auto &root = *_root;

	auto lBiggest = check(root.l);
	auto rBiggest = check(root.r);
	auto biggest = 3;

	if ((root.l && root.r)) {
		auto &l = root.l->to_array();
		auto &r = root.r->to_array();
		if (reverseWithCompare(l, r)) biggest = static_cast<int>(l.size() * 2 + 1);
	}

	return std::max(lBiggest, std::max(rBiggest, biggest));
}

auto main(int, char **) -> int {
	auto *root = build();
	std::cout << check(root) / 2 << std::endl;

	return 0;
}

#endif //LUOGU_U51945_HPP
