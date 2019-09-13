//
// Created by hoshino on 18-9-9.
//

#ifndef LUOGU_1563_HPP
#define LUOGU_1563_HPP

#include <iostream>
#include <string>
#include <vector>
#include <array>

struct Doll {
	enum Face { IN, OUT };
	enum Side { LEFT, RIGHT };

	Face face;
	std::string name;

	Doll() : face(IN), name("") { }
	Doll(const Face &f, std::string name) : face(f), name(std::move(name)) { }
};

auto findDoll(
		const Doll *dolls,
		const int size,
		int &index,
		const int &move,
		const Doll::Side &side) -> void {
	Doll::Face face = dolls[index].face;
	if ((int) side == face) {
		index = ((index - move) % size + size) % size;
	} else index = (index + move) % size;
}

auto main(int, char **) -> int {
	int dollCount, commandCount;
	std::cin >> dollCount >> commandCount;

	Doll *dolls = new Doll[dollCount];

	for (int i = 0; i < dollCount; ++i) {
		int face;
		std::string name;
		std::cin >> face >> name;

		dolls[i] = Doll(Doll::Face(face), name);
	}

	int index = 0;

	for (int i = 0; i < commandCount; ++i) {
		int side, step;
		std::cin >> side >> step;
		findDoll(dolls, dollCount, index, step, Doll::Side(side));
	}

	std::cout << dolls[index].name << std::endl;

	delete[] dolls;		//有用吗

	return 0;
}

#endif //LUOGU_1563_HPP
