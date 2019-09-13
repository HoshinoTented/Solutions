//
// Created by hoshino on 18-11-25.
//

#ifndef LUOGU_P2089_HPP
#define LUOGU_P2089_HPP

#include <bits/stdc++.h>

#define MIN 1
#define MAX 3
#define KIND_MAX 10
#define Program int[KIND_MAX]

std::vector<int *> programs;

auto dfs(const int &cur, const int &need, int *program) -> void {
	if (cur == KIND_MAX) {
		if (! need) {
			int *clonedProgram = new Program;
			for (int i = 0; i < KIND_MAX; ++ i) {
				clonedProgram[i] = program[i];
			}

			programs.push_back(clonedProgram);
		}
	} else
		for (int i = MIN; i <= MAX; ++ i) {
			auto newNeed = need - i;
			program[cur] = i;
			dfs(cur + 1, newNeed, program);
		}
}

auto main(int n, char **) -> int {
	std::cin >> n;
	dfs(0, n, new Program);

	std::cout << programs.size() << std::endl;

	for (auto &v : programs) {
		for (int i = 0; i < KIND_MAX; ++ i) {
			std::cout << v[i] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}

#endif //LUOGU_P2089_HPP
