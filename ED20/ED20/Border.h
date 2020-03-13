#pragma once
#include <vector>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal
*/

template <class T>
class Border : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	Border() : bintree<T>() {}
	Border(Border<T> const& l, T const& e, Border<T> const& r) : bintree<T>(l, e, r) {}

	std::vector<int> calculateBorder() {
		std::vector<int> border;
		calculateBorder(this->raiz, border);
		return border;
	}
private:
	static void calculateBorder(Link r, std::vector<int>& border) {
		if (r == nullptr) return;
		if (r->left == nullptr && r->right == nullptr) {
			border.push_back(r->elem);
		}
		calculateBorder(r->left, border);
		calculateBorder(r->right, border);
	}
};

template <typename T>
Border<T> readTree(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio)
		return {};
	
	else {
		auto iz = readTree(vacio);
		auto dr = readTree(vacio);
		return { iz, raiz, dr };
	}
}