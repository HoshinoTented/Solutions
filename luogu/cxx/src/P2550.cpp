//
// Created by hoshino on 18-8-25.
//

#ifndef LUOGU_2550_H
#define LUOGU_2550_H

#include <iostream>

#define MAX 7

auto read_array(int *arr) -> void {
	for (int i = 0; i < MAX; ++i) {
		std::cin >> arr[i];
	}
}

auto hit_count(const int *prize, const int *arr) -> const int {
	int hit_count = 0;
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			if (arr[i] == prize[j]) hit_count ++;
		}
	}

	return hit_count;
}
auto main(int argc, char *argv[]) -> int {
	int n;
	std::cin >> n;
	int *prize = new int[MAX];
	int *hits = new int[MAX];
	read_array(prize);

	for (int i = 0; i < n; ++i) {
		int *arr = new int[7];
		read_array(arr);
		int hit = hit_count(prize, arr);
		hits[hit - 1] ++;

		delete[] arr;
	}

	for (int i = MAX - 1; i > -1; --i) {
		std::cout << hits[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}

#endif //LUOGU_2550_H
