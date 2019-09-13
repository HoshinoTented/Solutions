//
// Created by hoshino on 18-9-15.
// 对不起, 星野实在是太鶸了, 只能抄书里的代码QAQ
// 虽然最后还是理解了, 但是罪恶感还是很深
// 星野果然还是太鶸了
// TODO TLE
// 还 TLE 了是最可怕的
// 辣鸡快排

#ifndef CPP_QUICK_SORT_HPP
#define CPP_QUICK_SORT_HPP

#include <iostream>

auto partition(int arr[], int low, int high) -> int {
	int pivotKey = arr[low];
	while (low < high) {
		while (low < high && arr[high] >= pivotKey)
			high --;
		std::swap(arr[low], arr[high]);
		while (low < high && arr[low] <= pivotKey)
			low ++;
		std::swap(arr[low], arr[high]);
	}

	return low;
}

auto q_sort(int *arr, const int &low, const int &high) -> void {
	if (low < high) {
		int pivot = partition(arr, low, high);
		q_sort(arr, low, pivot - 1);
		q_sort(arr, pivot + 1, high);
	}
}

auto quick_sort(int arr[], const int &begin, const int &end) -> void {
	q_sort(arr, begin, end - 1);
}

auto main(int, char **) -> int {
	int length;
	std::cin >> length;

	int arr[length];
	for (int i = 0; i < length; ++ i) {
		int tmp;
		std::cin >> tmp;
		arr[i] = tmp;
	}

	quick_sort(arr, 0, length);

	for (int i = 0; i < length; ++ i) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	return 0;
}

#endif //LUOGU_1177_HPP
