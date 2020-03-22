#include <iostream>

#include "bintree_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema, mediante una funci�n externa, averiguamos si un �rbol es sim�trico o no.
La funci�n tiene coste lineal respecto al n�mero de nodos.
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