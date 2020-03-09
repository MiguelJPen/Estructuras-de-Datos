#pragma once
#include <algorithm>

#include "bintree_eda.h"

template <class T>
class TreeData : public bintree<T> {
public:

	int leaves(TreeData<T> const& t) {
		if (t.empty())
			return 1;
		return nodes(t.left()) + nodes(t.right());
	}
	int nodes(TreeData<T> const& t) {
		if (t.empty())
			return 1;
		return nodes(t.left()) + nodes(t.right()) + 1;
	}
	int height(TreeData<T> const& t) {
		if (t.empty()) return 0;
		return max(height(t.left()), height(t.right())) + 1;
	}
};

// lee un árbol binario de la entrada estándar
template <typename T>
inline TreeData<T> readTree(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}