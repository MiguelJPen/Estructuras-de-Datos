#pragma once
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal
*/

template <class T>
class TreeData : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	TreeData() : bintree<T>() {}
	TreeData(TreeData<T> const& l, T const& e, TreeData<T> const& r) : bintree<T>(l, e, r) {}

	int leaves() {
		return leaves(this->raiz);
	}
	int nodes() {
		return nodes(this->raiz);
	}
	int height() {
		return height(this->raiz);
	}
private:
	static int height(Link r) {
		if (r == nullptr) return 0;
		return std::max(height(r->left), height(r->right)) + 1;
	}
	static int nodes(Link r) {
		if (r == nullptr) return 0;
		return nodes(r->left) + nodes(r->right) + 1;
	}
	static int leaves(Link r) {
		if (r == nullptr) return 0;
		if (r->left == nullptr && r->right == nullptr) return 1;
		return leaves(r->left) + leaves(r->right);
	}
};

template <typename T>
TreeData<T> readTreeData(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio)
		return {};
	
	else {
		auto iz = readTreeData(vacio);
		auto dr = readTreeData(vacio);
		return { iz, raiz, dr };
	}
}