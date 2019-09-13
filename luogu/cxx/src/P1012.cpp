//
// Created by hoshino on 18-9-17.
//

#ifndef LUOGU_1012_HPP
#define LUOGU_1012_HPP

#include <iostream>
#include <string>
#include <algorithm>

auto main(int, char **) -> int {
	int num;
	std::cin >> num;
	std::string nums[num];
	for (int i = 0; i < num; ++ i) {
		std::cin >> nums[i];
	}

	std::sort(nums, nums + num, [](const std::string &a, const std::string &b) -> bool {
		auto ai = a.begin(), bi = b.begin();
		while (ai != a.end() && bi != b.end()) {
			if (*ai != *bi) return *ai > *bi;

			++ ai;
			++ bi;
		}

		if (ai != a.end() || bi != b.end()) {
			auto end = -- (ai == a.end() ? b.end() : a.end());
			return *a.begin() > *end;
		}

		return true;
	});

	for (auto s : nums) std::cout << s;

	std::cout << std::endl;

	return 0;
}

#endif //LUOGU_1012_HPP
