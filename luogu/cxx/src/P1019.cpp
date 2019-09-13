//
// Created by Administrator on 2019/8/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

template<class T>
using Ptr = T *;

template<class T>
struct Node {
	struct Next {
		int length;        // increase length
		Ptr<Node<T>> next;
	};

	T value;
	std::vector<Next> next;
};

struct QueueNode {
	int length;
	Ptr<Node<std::string>> value;
	std::map<std::string, int> used;
};

auto equalSub(const std::string &a, const std::string &b, const int &len) -> bool {
	int aIt = a.size() - len, bIt = 0;
	int min = std::min(a.size(), b.size());

	while (aIt < a.size() && bIt < len) {
		if (a[aIt] != b[bIt]) return false;

		++ aIt;
		++ bIt;
	}

	return true;
}

/**
 * check two string are able to connect or not
 * @param a a string
 * @param b a string
 * @return return the length of matched substring
 */
auto canConnect(const std::string &a, const std::string &b) -> int {
	int i, min = std::min(a.size(), b.size());

	for (i = 1; i <= min; ++ i) {
		if (equalSub(a, b, i)) return i != min ? i : - 1;
	}

	return - 1;
}

auto bfs(char start, std::vector<Ptr<Node<std::string>>> vec) -> int {
	int longest = 0;
	std::queue<QueueNode> q;
	std::map<std::string, int> initMap;

	for (auto &ptr : vec) {
		initMap.insert({ptr->value, 2});
	}

	for (auto &ptr : vec) {
		if (ptr->value[0] == start) {
			QueueNode node;

			node.length = ptr->value.size();
			node.value = ptr;
			node.used.insert(initMap.cbegin(), initMap.cend());
			node.used.find(ptr->value)->second -= 1;

			q.push(node);
		}
	}

	while (! q.empty()) {
		QueueNode cur = q.front();
		longest = std::max(longest, cur.length);
		q.pop();

		for (auto &ptr : cur.value->next) {
			if (cur.used.find(ptr.next->value)->second == 0) continue;

			QueueNode node;

			node.value = ptr.next;
			node.length = cur.length + ptr.length;
			node.used = cur.used;
			node.used.find(ptr.next->value)->second -= 1;

			q.push(node);
		}
	}

	return longest;
}

auto main(int, char **) -> int {
	int n;
	std::cin >> n;
	std::vector<Ptr<Node<std::string>>> words;
	words.reserve(n);

	for (int i = 0; i < n; ++ i) {
		std::string line;
		std::cin >> line;

		auto node = new Node<std::string>();

		node->value = line;
		words.push_back(node);
	}

	char begin;
	std::cin >> begin;

	// build graph

	for (auto &node : words) {
		for (auto &tar : words) {
			int length = canConnect(node->value, tar->value);

			if (length != - 1) {
				Node<std::string>::Next next{};
				next.next = tar;
				next.length = tar->value.length() - length;

				node->next.push_back(next);
			}
		}
	}

	std::cout << bfs(begin, words) << std::endl;

	return 0;
}
