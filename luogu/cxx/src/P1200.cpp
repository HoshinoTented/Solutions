//
// Created by hoshino on 18-9-8.
//

#ifndef LUOGU_1200_HPP
#define LUOGU_1200_HPP

#include <iostream>
#include <string>

#define GO "GO"
#define STAY "STAY"

using namespace std;

auto eval(const string &str) -> int {
	int n = 1;
	for (char i : str) {
		n *= i - 'A' + 1;
	}

	return n % 47;
}

auto main(int, char **) -> int {
	string a, b;
	cin >> a >> b;

	cout << (eval(a) == eval(b) ? GO : STAY) << endl;

	return 0;
}

#endif //LUOGU_1200_HPP
