//
// Created by hoshino on 18-8-26.
//

#ifndef LUOGU_1093_H
#define LUOGU_1093_H

#include <iostream>
#include <vector>

#define MAX 5
#define self (*this)

class Student {
public:
	typedef unsigned int id_type;
	typedef unsigned int score_type;

	explicit Student() : id(0), chinese(0), math(0), english(0), score(0) { }

	explicit Student(const id_type &id,
			const score_type &ch,
			const score_type &ma,
			const score_type &en) :
			id(id), chinese(ch), math(ma), english(en), score(chinese + math + english) {  }

	inline auto getId() const -> const id_type & {
		return id;
	}

	inline auto getScore() const -> const score_type & {
		return score;
	}

	auto operator<(const Student &other) const -> const bool {
		if (score < other.score) {
			return true;
		} else if (score == other.score) {
			if (chinese < other.chinese) {
				return true;
			} else if (chinese == other.chinese && id > other.id) {
				return true;
			}
		}

		return false;
	}

	auto to_string() -> std::string {
		return std::to_string(id) + " " + std::to_string(score);
	}

private:
	id_type id;
	score_type chinese;
	score_type math;
	score_type english;
	score_type score;
};

template <typename value_type>
auto push_with_sort(std::vector<value_type> &v, const value_type &value) -> void {
	if (! v.empty()) {
		auto it = v.cbegin();
		auto end = v.cend();
		while (it != end) {
			if (*it < value) {
				v.insert(it, value);
				break;
			}

			++ it;
		}

		v.resize(MAX);
	} else v.push_back(value);
}

auto readScores(const Student::id_type &id) -> const Student {
	Student::score_type ch, ma, en;
	std::cin >> ch >> ma >> en;
	return Student(id, ch, ma, en);
}

auto main(int argc, char *argv[]) -> int {
	std::vector<Student>::size_type studentCount;
	std::cin >> studentCount;

	std::vector<Student> students(MAX);
	for (Student::id_type i = 0; i < studentCount; ++i) {
		push_with_sort(students, readScores(i + 1));
	}

	for (auto value : students) {
		std::cout << value.to_string() << std::endl;
	}

	return 0;
}

#endif //LUOGU_1093_H
