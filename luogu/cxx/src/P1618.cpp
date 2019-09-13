#include <iostream>
#include <string>

auto check_(bool *arr, int i) -> bool {
	std::string str = std::to_string(i);

	if (str.size() != 3) return false;

	for (char &c : str) {
		if (c == '0') return false;
		if (arr[c - '0']) {
			arr[c - '0'] = false;
		} else return false;
	}

	return true;
}

auto check(int a, int b, int c) -> bool {
	bool arr[10];
	for (bool &b : arr) {
		b = true;
	}

	return check_(arr, a) && check_(arr, b) && check_(arr, c);
}

auto main(int, char **) -> int {
	int a, b, c;
	bool hasAns = false;
	std::cin >> a >> b >> c;

	for (int i = 0; i < 1000; ++ i) {
		int first = i * a;
		int second = i * b;
		int third = i * c;

		if (check(first, second, third)) {
			hasAns = true;
			std::cout << first << " " << second << " " << third << std::endl;
		}
	}

	if (! hasAns) std::cout << "No!!!" << std::endl;

	return 0;
}