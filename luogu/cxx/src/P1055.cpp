//
// Created by hoshino on 18-9-7.
//

#ifndef LUOGU_1055_HPP
#define LUOGU_1055_HPP

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct ISBN {
	string lang, pub, id;
	char check_number;

	ISBN(string lang, string pub, string id, char check_number) : lang(move(lang)), pub(move(pub)), id(
			move(id)), check_number(check_number) {}

	auto to_string_without_check_number() const -> string {
		return lang + pub + id;
	}

	auto to_string() const -> string {
		return lang + '-' + pub + '-' + id + '-' + check_number;
	}
};

auto compute_check_number(const ISBN &isbn) -> char {
	int sum = 0;
	auto str = isbn.to_string_without_check_number();
	for (size_t i = 0 ; i < str.length() ; ++ i) {
		sum += (str.at(i) - '0') * (i + 1);
	}

	int n = sum % 11;
	return n == 10 ? 'X' : *to_string(n).cbegin();
}

auto check_number(const ISBN &isbn) -> bool {
	return compute_check_number(isbn) == isbn.check_number;
}

auto main(int argc, char *argv[]) -> int {
	int lang, pub, id;
	char check_n;
	scanf("%d-%d-%d-%c", &lang, &pub, &id, &check_n);
	ISBN isbn(to_string(lang), to_string(pub), to_string(id), check_n);
	if (check_number(isbn)) {
		cout << "Right";
	} else {
		isbn.check_number = compute_check_number(isbn);
		cout << isbn.to_string();
	}

	cout << endl;

	return 0;
}

#endif //LUOGU_1055_HPP
