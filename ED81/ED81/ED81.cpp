#include <iostream>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema, mediante una función externa, averiguamos si un árbol es simétrico o no.
La función tiene coste lineal respecto al número de nodos.
*/

bool isSim(bintree<char> const& left, bintree<char> const& right) {
	if (left.empty() && right.empty()) return true;
	if (!(left.empty() || right.empty())) {
		return isSim(left.left(), right.right()) && isSim(left.right(), right.left());
	}
	else return false;
}

void resuelveCaso() {
	bintree<char> t;
	t = leerArbol('.');

	bool simetric = (t.empty() || isSim(t.left(), t.right()));

	std::cout << (simetric ? "SI" : "NO") << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}