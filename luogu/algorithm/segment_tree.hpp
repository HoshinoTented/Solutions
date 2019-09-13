#ifndef LUOGU_ALGORITHM_SEGMENT_TREE_HPP
#define LUOGU_ALGORITHM_SEGMENT_TREE_HPP

#include <bits/stdc++.h>

#define TODO() (throw std::runtime_error("No implementation"))

using value_type = int;

struct Range : std::pair<size_t, size_t> {
	Range(const size_t &begin, const size_t &end) : pair(begin, end) {}

	inline auto length() const -> size_t {
		return second - first;
	}

	inline auto begin() const -> size_t {
		return first;
	}

	inline auto end() const -> size_t {
		return second;
	}

	inline auto operator>(const Range &other) const -> bool {
		return begin() < other.begin() || end() > other.begin();
	}

	inline auto operator<(const Range &other) const -> bool {
		return other.begin() < begin() && other.end() > end();
	}

	inline auto operator<=(const Range &other) const -> bool {
		return other.begin() <= begin() && other.end() >= end();
	}

	inline auto operator==(const Range &other) const -> bool {
		return begin() == other.begin() && end() == other.end();
	}

	inline auto contains(const size_t &v) const -> bool {
		return begin() <= v && v < end();
	}

	inline auto include(const Range &range) const -> bool {
		return range <= (*this);
	}
};

struct Tree {
	value_type value;
	Tree *l, *r;
	Range range;

	explicit Tree(const value_type &value, Tree *l, Tree *r, Range range) : value(value), l(l), r(r),
																			range(std::move(range)) {}

	~Tree() {
		delete l;
		delete r;
	}

	auto to_string() const -> std::string {
		std::string lS = l ? l->to_string() : "null";
		std::string rS = r ? r->to_string() : "null";
		return "(" + std::to_string(value) + " " + lS + " " + rS + ")";
	}

	inline auto operator<(const Tree &other) const -> bool {
		return value < other.value;
	}

	inline auto operator>(const Tree &other) const -> bool {
		return value > other.value;
	}
};

struct Leaf : public Tree {
	explicit Leaf(const value_type &value, Range range) : Tree(value, nullptr, nullptr, std::move(range)) {}
};

inline auto compare(const Tree &a, const Tree &b) -> const Tree & {
	return std::min(a, b);
}

template<typename T>
inline auto odd(const T &v) -> bool {
	return static_cast<bool>(v & 1);
}

auto buildTree(
		value_type *tree,
		const size_t &len,
		const Range &range) -> Tree * {
	if (range.length() == 1) return new Leaf(tree[range.begin()], range);
	size_t mLen = range.length();
	size_t mid = range.begin() + mLen / 2 + odd(mLen);
	auto l = buildTree(tree, len, {range.begin(), mid});
	auto r = buildTree(tree, len, {mid, range.end()});
	value_type v = compare(*l, *r).value;

	return new Tree(v, l, r, range);
}

auto find(const Tree &node, const Range &range) -> const Tree & {
	if (node.range == range) return node;
	if (node.l->range.include(range)) return *node.l;
	if (node.r->range.include(range)) return *node.r;

	auto &lN = find(*node.l, {range.begin(), node.l->range.end()});
	auto &rN = find(*node.r, {node.r->range.begin(), range.end()});

	return compare(lN, rN);
}

auto updateNode(Tree &node, const size_t &index, const value_type &nValue) -> void {
	auto child = node.l->range.contains(index) ? node.l : node.r;
	if (child->l && child->r) {
		updateNode(*child, index, nValue);
		child->value = compare(*child->l, *child->r).value;
	} else child->value = nValue;

	node.value = compare(*node.l, *node.r).value;
}

auto main(int, char **) -> int {
	constexpr value_type len = 5;
	auto *arr = new value_type[len]{5, 2, 1, 4, 3};
	auto tree = *buildTree(arr, len, {0, len});
	std::cout << tree.to_string() << std::endl;
	updateNode(tree, 2, 6);
	std::cout << tree.to_string() << std::endl;

	std::cout << find(tree, {1, 5}).value << std::endl;

	return 0;
}

#endif  //LUOGU_ALGORITHM_SEGMENT_TREE_HPP
