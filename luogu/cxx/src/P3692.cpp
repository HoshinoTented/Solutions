//
// Created by hoshino on 18-8-26.
// @akemimadoka

#ifndef LUOGU_3692_H
#define LUOGU_3692_H

#include <iostream>
#include <vector>
#include <sstream>

#define self (*this)

class Id {
public:
	enum TestType {
		A, B, WRONG
	};

	explicit Id(const std::string &id) {
		std::stringstream stream(id);
		const char *charArr = id.c_str();
		self.id = static_cast<int>(std::strtol(charArr, (char **) (charArr + id.size()), 2));
		self.testType = *(--id.cend()) - '0' ? B : A;
	}

	explicit Id(const int &id, const TestType &type) : id(id), testType(type) {}

	inline auto getId() -> int { return id; }

	inline auto getType() -> TestType { return testType; };

private:
	int id;
	TestType testType;        // true: 10 false: 01

};

class SingleAnswer {
private:
	enum Answer {
		A, B, C, D, WRONG
	};
	Answer ans;

public:
	explicit SingleAnswer() : ans(WRONG) {}

	explicit SingleAnswer(const char &ans) {
		switch (ans) {
			case 'A':
				self.ans = A;
				break;
			case 'B':
				self.ans = B;
				break;
			case 'C':
				self.ans = C;
				break;
			case 'D':
				self.ans = D;
				break;
			default:
				self.ans = WRONG;
		}
	}

	explicit SingleAnswer(const std::string &str) {
		if (str.size() != 4) throw "Error";
		if (str == "1000") ans = A;
		else if (str == "0100") ans = B;
		else if (str == "0010") ans = C;
		else if (str == "0001") ans = D;
		else ans = WRONG;
	}

	auto operator==(const SingleAnswer &ans) -> bool const {
		return self.ans == ans.ans;
	}
};

auto readId() -> const Id {
	std::string id;
	std::cin >> id;
	return Id(id);
}

auto readType() -> const Id::TestType {
	int type;
	std::cin >> type;

	if (type == 10) return Id::A;
	else if (type == 1) return Id::B;
	else return Id::WRONG;
}

auto readAnswers() -> const std::vector<SingleAnswer> {
	std::string answers;
	std::cin >> answers;
	std::vector<SingleAnswer> ans;
	for (auto c : answers) {
		ans.emplace_back(c);
	}

	return ans;
}

auto readInputAnswer(const int &answerCount) -> const std::vector<SingleAnswer> {
	std::vector<SingleAnswer> answers;
	for (int i = 0; i < answerCount; ++i) {
		std::string ans;
		std::cin >> ans;

		answers.emplace_back(ans);
	}

	return answers;
}

auto main(int argc, char *argv[]) -> int {
	int ansCount, ansLength;
	std::cin >> ansCount >> ansLength;

	auto ans = readAnswers();

	for (int i = 0; i < ansCount; ++i) {
		auto id = readId();
		auto type = readType();
		auto inputAnswers = readInputAnswer(ansLength);

		if (id.getId() == 0 || id.getId() > 10000) {
			std::cout << "Wrong ID" << std::endl << std::endl;
			continue;
		} else std::cout << "ID: " << id.getId() << std::endl;
		std::cout
				<< "Type "
				<< (id.getType() == type ? "Correct" : "Incorrect")
				<< std::endl;

		int correctCount = 0;
		auto ansIt = ans.cbegin();

		for (auto inputAnswer : inputAnswers) {
			correctCount += inputAnswer == *ansIt++;
		}

		printf("%.1f\n\n", 100.0 / ansLength * correctCount);
	}

	return 0;
}

#endif //LUOGU_3692_H
