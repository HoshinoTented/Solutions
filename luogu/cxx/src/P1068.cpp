//
// Created by hoshino on 18-9-15.
//

#ifndef LUOGU_1068_HPP
#define LUOGU_1068_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Score {
	int id, score;

	Score(const int &id, const int &score) : id(id), score(score) {}

	auto to_string() const -> std::string {
		return std::to_string(id) + " " + std::to_string(score);
	}
};


auto insert_with_sort(std::vector<Score> &vector, const Score &value) -> bool {
	if (! vector.empty()) {
		auto it = vector.cbegin();
		while (it != vector.cend()) {
			if (value.score > it->score) {
				vector.insert(it, value);
				return false;
			} else if (value.score == it->score) {
				while (it != vector.cend() && value.id > it->id && value.score == it->score) ++ it;
				vector.insert(it, value);
				return false;
			}

			++ it;
		}

		vector.push_back(value);
	} else vector.push_back(value);

	return false;
}

auto main(int, char **) -> int {
	int max, wanted;
	std::vector<Score> v;

	std::cin >> max >> wanted;

	int partition = static_cast<int>(wanted * 1.5);

	v.reserve(static_cast<unsigned long>(max));
	for (int i = 0; i < max; ++ i) {
		int id, score;
		std::cin >> id >> score;
		insert_with_sort(v, {id, score});
	}

	int scoreLine = v[partition - 1].score;

	std::vector<Score> final;

	for (auto score : v) {
		if (score.score >= scoreLine) {
			final.push_back(score);
		}
	}

	std::cout << scoreLine << " " << final.size() << std::endl;
	for (auto score : final) {
		std::cout << score.to_string() << std::endl;
	}

	return 0;
}

#endif //LUOGU_1068_HPP
