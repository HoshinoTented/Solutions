//
// Created by hoshino on 18-10-5.
//

/*
 * README
 * 这道题目的测试点1
 * 有点毒(test/1308/test1)
 * 下载下来的数据是 AC 不了的
 * 但是提交的代码却 AC 了
 * emmmmmmmm
 * */

#ifndef LUOGU_1308_HPP
#define LUOGU_1308_HPP

#include <iostream>
#include <string>

#define SEPARATOR ' '

auto main(int, char **) -> int {
	int times = 0, first = - 1;
	std::string req, article, tmp;
	std::getline(std::cin, req);
	std::getline(std::cin, article);

	article.push_back(SEPARATOR);

	for (auto &c : req) {
		c = static_cast<char>(std::tolower(c));
	}

	for (size_t i = 0; i < article.size(); ++ i) {
		if (article[i] == SEPARATOR) {
			if (req == tmp) {
				if (first == - 1) {
					first = static_cast<int>(i - tmp.size());
				}

				++ times;
			}

			tmp = {};
		} else tmp.push_back(static_cast<char>(std::tolower(article[i])));
	}

	if (times) std::cout << times << " " << first << std::endl;
	else std::cout << - 1 << std::endl;

	return 0;
}

#endif //LUOGU_1308_HPP
