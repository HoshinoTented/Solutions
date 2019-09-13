#include <utility>

//
// Created by hoshino on 18-9-24.
//

#ifndef LUOGU_1051_HPP
#define LUOGU_1051_HPP

#include <iostream>
#include <string>

struct Student {
	static const Student EMPTY;

	std::string name;
	int endingScore, dissScore, articleCount;
	bool isGanbu, isWest;
	int finalPrize;

	Student(std::string name, const int &endingScore, const int &dissScore, const bool &isGanbu,
			const bool &isWest, const int &articleCount) : name(std::move(name)), endingScore(endingScore),
														   dissScore(dissScore),
														   articleCount(articleCount), isGanbu(isGanbu),
														   isWest(isWest), finalPrize(0) {
		if (endingScore > 80 && articleCount >= 1) finalPrize += 8000;
		if (endingScore > 85 && dissScore > 80) finalPrize += 4000;
		if (endingScore > 90) finalPrize += 2000;
		if (endingScore > 85 && isWest) finalPrize += 1000;
		if (dissScore > 80 && isGanbu) finalPrize += 850;
	}
};

const Student Student::EMPTY{"unknown", 0, 0, false, false, 0};

auto main(int, char **) -> int {
	int count;
	std::cin >> count;

	auto sum = 0;
	auto max = Student::EMPTY;
	for (int i = 0; i < count; ++ i) {
		std::string name;
		int endS, dissS, articleC;
		char isGB, isW;
		std::cin >> name >> endS >> dissS >> isGB >> isW >> articleC;
		Student student{name, endS, dissS, isGB == 'Y', isW == 'Y', articleC};
		if (student.finalPrize > max.finalPrize) max = student;
		sum += student.finalPrize;
	}

	std::cout << max.name << std::endl;
	std::cout << max.finalPrize << std::endl;
	std::cout << sum << std::endl;

	return 0;
}

#endif //LUOGU_1051_HPP
