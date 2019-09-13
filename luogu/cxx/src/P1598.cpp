//
// Created by hoshino on 18-10-9.
//

#ifndef LUOGU_1598_HPP
#define LUOGU_1598_HPP

#include <iostream>
#include <string>
#include <vector>

#define MAX 4
#define SIGN '*'

/*
                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/

class Graph {
private:
	std::vector<std::string> graph;

public:
	Graph() {
		graph.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	}

	auto add(const char &c, const size_t &count) -> void {
		if (graph.size() - 1 < count) {
			graph.resize(count + 1, "                          ");
		}

		for (size_t i = 0; i < count; ++ i) {
			graph[i + 1][c - 'A'] = SIGN;
		}
	}

	auto print() const -> void {
		for (int it = graph.size() - 1; it > - 1; -- it) {
			auto &line = graph[it];
			for (size_t i = 0; i < line.size(); ++ i) {
				std::cout << line[i];

				if (i != line.size() - 1) {
					std::cout << ' ';
				} else std::cout << std::endl;
			}
		}
	}
};

auto main(int, char **) -> int {
	int count[26];

	for (int &i : count) {
		i = 0;
	}

	for (int i = 0; i < MAX; ++ i) {
		std::string line;
		std::getline(std::cin, line);

		for (const auto &c : line) {
			if (isalpha(c)) {
				++ count[c - 'A'];
			}
		}
	}

	Graph graph;

	for (int i = 0; i < 26; ++ i) {
		graph.add(static_cast<const char &>(i + 'A'), static_cast<const size_t &>(count[i]));
	}

	graph.print();

	return 0;
}

#endif //LUOGU_1598_HPP
