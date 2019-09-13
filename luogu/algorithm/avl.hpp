//
// Created by hoshino on 18-11-18.
//

#ifndef LUOGU_AVL_HPP
#define LUOGU_AVL_HPP

using T = int;

template<class T>
using Ptr = T *;

template<class T>
using Ref = T &;

typedef struct BiTNode {
	T data;
	int bf;
	Ptr<BiTNode> left, right;
} *BiTree;

auto R_Rotate(Ptr<BiTree> P) -> void {
	BiTree L;
	L = (*P)->left;
	(*P)->left = L->right;
	L->right = *P;
	(*P) = L;
}

auto L_Rotate(Ptr<BiTree> P) -> void {
	BiTree R;
	R = (*P)->right;
	(*P)->right = R->left;
	R->left = *P;
	*P = R;
}


#endif //LUOGU_AVL_HPP
