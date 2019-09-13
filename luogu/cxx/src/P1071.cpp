//
// Created by hoshino on 18-9-17.
// 暴力...

#ifndef LUOGU_1071_HPP
#define LUOGU_1071_HPP
//#define LUOGU_1071_HPP_DEBUG

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define F "Failed"

auto logFailed() -> void {
	std::cout << F << std::endl;
}

auto main(int, char **) -> int {
	std::string encoded, decoded, code;
#ifdef LUOGU_1071_HPP_DEBUG
	encoded = "MSRTZCJKPFLQYVAWBINXUEDGHOOILSMIJFRCOPPQCEUNYDUMPP";
	decoded = "YIZSDWAHLNOVFUCERKJXQMGTBPPKOIYKANZWPLLVWMQJFGQYLL";
	code = "FLSO";
#else
	std::cin >> encoded >> decoded >> code;
#endif

	std::vector<char> dic(26, '\0');

	for (auto ei = encoded.begin(), di = decoded.begin(); ei != encoded.end(); ++ ei, ++ di) {
		auto it = dic.begin() + *ei - 'A';
		if (*it != '\0') {
			if (*it != *di) {
				logFailed();
				return 0;
			}
		} else {
			if (std::find(dic.begin(), dic.end(), *di) != dic.end()) {
				logFailed();
				return 0;
			}
			*it = *di;
		}
	}

	if (std::find(dic.begin(), dic.end(), '\0') != dic.end()) {
		logFailed();
		return 0;
	}

	for (auto c : code) {
		auto it = dic.begin() + c - 'A';
		if (*it == '\0') {
			logFailed();
			return 0;
		} else std::cout << *it;
	}

	std::cout << std::endl;

	return 0;
}

#endif //LUOGU_1071_HPP
