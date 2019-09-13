//
// Created by hoshino on 18-11-13.
//

#ifndef LUOGU_TREE_HPP
#define LUOGU_TREE_HPP

#include <string>

namespace hoshino {
	template<typename value_type>
	class tree {
	public:
		value_type value;
		tree *l, *r;

		tree(const value_type &, tree *, tree *);

		auto to_string(std::string (*)(value_type)) const -> std::string;
	};
}


#endif //LUOGU_TREE_HPP
