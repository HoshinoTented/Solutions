//
// Created by hoshino on 18-11-10.
//

#ifndef LUOGU_U51942_HPP
#define LUOGU_U51942_HPP

#include <bits/stdc++.h>

using integer = unsigned long long;

integer n, m, p1, s1, s2;
integer *forces;

integer forceL = 0, forceR = 0;

auto _forceL(const integer &i) -> integer {
	return forces[i] * (m - i);
}

auto _forceR(const integer &i) -> integer {
	return forces[i] * (i - m);
}

auto main(int, char **) -> int {
	std::cin >> n;
	forces = new integer[n];
	for (integer i = 0; i < n; ++ i) std::cin >> forces[i];
	std::cin >> m >> p1 >> s1 >> s2;

	m -= 1;
	p1 -= 1;

	forces[p1] += s1;

	auto init = [](const bool &isForceL) { return isForceL ? 0 : m + 1; };
	auto range = [](const bool &isForceL, const integer &i) { return isForceL ? i < m : i < n; };
	auto forceF = [](const bool &isForceL) { return isForceL ? _forceL : _forceR; };
	auto forceS = [](const bool &isForceL) -> integer & { return isForceL ? forceL : forceR; };

	for (integer i = init(true); range(true, i); ++ i) {
		forceL += _forceL(i);
	}

	for (integer i = init(false); range(false, i); ++ i) {
		forceR += _forceR(i);
	}

	auto bigger = std::max(forceL, forceR);
	auto smaller = std::min(forceL, forceR);
	integer minDiff = bigger - smaller, id = m;
	auto isForceL = smaller == forceL;

	for (integer i = init(isForceL); range(isForceL, i) && minDiff != 0; ++ i) {
		auto _forceF = forceF(isForceL);
		integer newForce = forceS(isForceL) - _forceF(i);
		forces[i] += s2;
		newForce += _forceF(i);
		integer newDiff = std::max(newForce, forceS(! isForceL)) - std::min(newForce, forceS(! isForceL));
		if (newDiff < minDiff || (newDiff == minDiff && id > i)) {
			minDiff = newDiff;
			id = i;
		}

		forces[i] -= s2;
	}

	std::cout << id + 1 << std::endl;

	return 0;
}

#endif //LUOGU_U51942_HPP
