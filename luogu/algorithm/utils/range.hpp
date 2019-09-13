//
// Created by hoshino on 18-11-13.
//

#ifndef LUOGU_RANGE_HPP
#define LUOGU_RANGE_HPP

#include <cstdio>
#include <iterator>

namespace hoshino {
	class range {
	public:
		range(const std::size_t &, const std::size_t &);

		inline auto length() const -> std::size_t;
	};
}


#endif //LUOGU_RANGE_HPP
