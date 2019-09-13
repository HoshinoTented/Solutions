//
// Created by hoshino on 18-9-13.
//

#ifndef LUOGU_BIGINT_HPP
#define LUOGU_BIGINT_HPP

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class BigInt {
public:
	using bits_type = vector<int>;

	explicit BigInt(const string &str) {
		auto s = str;
		if (*str.cbegin() == '-') {
			negative = true;
			s = str.substr(1);
		}

		bits = string2bits(s);
	}

	explicit BigInt(const bits_type &bits, const bool &isNegative = false) : negative(false), bits(bits) {}

	auto operator+(const BigInt &other) const -> BigInt {
		bits_type otherBits = other.get_bits(), newBits;
		auto maxBits = (otherBits.size() < size() ? bits : otherBits);
		auto minBits = (otherBits.size() >= size() ? bits : otherBits);
		auto minIt = minBits.cbegin(), maxIt = maxBits.cbegin();
		auto minEnd = minBits.cend(), maxEnd = maxBits.cend();

		bool inc = false;

		while (minIt != minEnd) {
			int result = (*minIt ++) + (*maxIt ++) + inc;
			inc = result >= 10;
			result %= 10;

			newBits.push_back(result);
		}

		while (maxIt != maxEnd) {
			int result = *maxIt ++ + inc;
			inc = result >= 10;
			result %= 10;

			newBits.push_back(result);
		}

		if (inc) newBits.push_back(inc);

		return BigInt(newBits);
	}

	auto operator-(const BigInt &other) const -> BigInt {
		bits_type otherBits = other.get_bits(), newBits;
		auto maxBits = (otherBits.size() < size() ? bits : otherBits);
		auto minBits = (otherBits.size() >= size() ? bits : otherBits);
		auto minIt = minBits.cbegin(), maxIt = maxBits.cbegin();
		auto minEnd = minBits.cend(), maxEnd = maxBits.cend();

	}

	static auto to_string(const bits_type &bits) -> string {
		string s;
		for (auto v : bits) {
			s += std::to_string(v);
		}

		std::reverse(s.begin(), s.end());

		return s;
	}

	auto size() const -> bits_type::size_type {
		return bits.size();
	}

	auto is_negative() const -> bool {
		return this->negative;
	}

	auto get_bits() const -> bits_type {
		return this->bits;
	}

	auto get_bits() -> bits_type & {
		return this->bits;
	}

	auto operator>(const BigInt &other) const -> bool {
		if ((negative || other.is_negative()) && negative != other.is_negative()) return ! negative;
		bool isNegative = negative && other.is_negative();
		if (size() != other.size()) return size() > other.size();
		auto it = bits.cbegin(), ot = other.get_bits().cbegin();
		while (it != bits.cend()) {
			if (*it < *ot) return isNegative;
		}

		return ! isNegative;
	}

	auto operator<(const BigInt &other) const -> bool {
		if (size() != other.size()) return size() > other.size();
		auto it = bits.cbegin(), ot = other.get_bits().cbegin();
		while (it != bits.cend()) {
			if (*it > *ot) return true;
		}

		return false;
	}

	auto to_string() const -> string {
		return (this->negative ? std::string("-") : std::string("")) + to_string(this->bits);
	}

	static auto string2bits(string num) -> bits_type {
		std::reverse(num.begin(), num.end());
		return string2bits(num.cbegin(), num.cend());
	}

	//需要 reverse
	static auto string2bits(string::const_iterator begin, string::const_iterator end) -> bits_type {
		bits_type bits;
		while (begin != end) {
			bits.push_back(- '0' + *begin ++);
		}

		return bits;
	}

private:
	bool negative;
	bits_type bits;
};

#endif //LUOGU_BIGINT_HPP
