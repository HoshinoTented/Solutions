//
// Created by hoshino on 18-9-13.
//

#ifndef LUOGU_1089_HPP
#define LUOGU_1089_HPP

#include <iostream>

#define INCREASE 300
#define MONTH_MAX 12
//#define LUOGU_1089_HPP_DEBUG

#ifdef LUOGU_1089_HPP_DEBUG

int cost[] = {290,
			  230,
			  280,
			  200,
			  300,
			  170,
			  330,
			  50,
			  90,
			  80,
			  200,
			  60};
#endif

auto main(int, char **) -> int {
	int free, saved;
	free = saved = 0;
	for (int i = 1; i <= MONTH_MAX; ++i) {
		int thisMonth = free, need;
#ifdef LUOGU_1089_HPP_DEBUG
		need = cost[i - 1];
#else
		std::cin >> need;
#endif
		thisMonth += INCREASE;
		thisMonth -= need;
		if (thisMonth >= 0) {
			int hundred = thisMonth / 100 * 100;        //为了丢精
			saved += hundred;
			free = thisMonth - hundred;
		} else {
			std::cout << i * -1 << std::endl;
			return 0;
		}
	}

	std::cout << saved * 1.2 + free << std::endl;

	return 0;
}

#endif //LUOGU_1089_HPP
