#pragma once
#include <string>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal
*/

template <class T>
class Minimum : public bintree<T> {
	using Link = typename bintree<T>::Link;
public:
	Minimum() : bintree<T>() {}
	Minimum(Minimum<T> const& l, T const& e, Minimum<T> const& r) : bintree<T>(l, e, r) {}

	T calculateMinimum() {
		return calculateMinimum(this->raiz);
	}
private:
	static T calculateMinimum(Link r) {
		T minl = r->elem, minr = r->elem;
		if (r->left != nullptr) minl = std::min(calculateMinimum(r->left), r->elem);
		if (r->right != nullptr) minr = std::min(calculateMinimum(r->right), r->elem);
		
		return std::min(minl, minr);
	}
};

template <typename T>
Minimum<T> readTree(T vacio) {
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