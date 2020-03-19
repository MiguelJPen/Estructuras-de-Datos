#pragma once
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal
*/

template <class T>
class isBS : public bintree<T> {
	using Link = typename bintree<T>::Link;
	typedef struct {
		bool ok;
		long int mayor, menor;
	}tNode;
public:
	isBS() : bintree<T>() {}
	isBS(isBS<T> const& l, T const& e, isBS<T> const& r) : bintree<T>(l, e, r) {}

	bool correct() {
		return (this->empty() ? true : correct(this->raiz).ok);
	}
private:
	static tNode correct(Link r) {
		tNode ret = { true, r->elem, r->elem };

		// El elemento de la raíz debe ser mayor que todos los elementos de los nodos izquierdos
		// y menor que todos los nodos derechos.
		if (r->left != nullptr) {
			tNode left = correct(r->left);
			ret.ok = left.ok && left.mayor < r->elem;
			ret.menor = left.menor;
		}
			
		if (r->right != nullptr) {
			tNode right = correct(r->right);
			ret.ok = right.ok && right.menor > r->elem && ret.ok;
			ret.mayor = right.mayor;
		}
		return ret;
	}
};

template <typename T>
isBS<T> readTree(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio)
		return {};
	
	else {
		auto iz = readTree(vacio);
		auto dr = readTree(vacio);
		return { iz, raiz, dr };
	}
};