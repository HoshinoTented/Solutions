//TODO TLE

#ifndef LUOGU_P1198_HPP
#define LUOGU_P1198_HPP

#include <bits/stdc++.h>

using namespace std;
using value_type = long;

inline auto compare(const value_type &a, const value_type &b) -> const value_type & {
	return max(a, b);
}

auto update(vector<value_type> &arr, const size_t &index, const value_type &v) -> void {
	arr[index] = v;
	if (! index) return;
	value_type parentValue = compare(arr[index], arr[index - 1]);
	if (parentValue == arr[index]) update(arr, index - 2, parentValue);
}

auto push(vector<value_type> &arr, const value_type &v) -> void {
	if (! arr.empty())
		arr.push_back(*(arr.end() - 1));
	arr.push_back(v);
	update(arr, arr.size() - 1, v);
}

inline auto find(vector<value_type> &arr, const size_t &C, const size_t &L) -> value_type {
	return arr[(C - L) * 2];
}

auto main(int, char **) -> int {
	value_type last = 0;
	size_t reqC, C = 0;
	value_type D;
	vector<value_type> arr;

	arr.reserve(200000);

	cin >> reqC >> D;

	for (size_t i = 0; i < reqC; ++ i) {
		char command;
		size_t arg;
		cin >> command >> arg;
		if (command == 'A') {
			++ C;
			push(arr, (arg + last) % D);
		} else {
			last = find(arr, C, arg);
			cout << last << endl;
		}
	}

	return 0;
}

#endif //LUOGU_P1198_HPP
