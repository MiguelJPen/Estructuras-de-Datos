#include <iostream>

#include "bintree_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema devolvemos la altura del �rbol completo m�s grande.
El coste de este algoritmo es lineal respecto al n�mero de nodos del �rbol.
*/

typedef struct {
	int heightComplete, maxComplete;
}tComplete;

tComplete biggerTree(bintree<char> const& t) {
	if (t.empty()) return { 0, 0 };
	
	tComplete left = biggerTree(t.left()), right = biggerTree(t.right()), ret;
	ret.heightComplete = std::min(left.heightComplete, right.heightComplete) + 1;
	ret.maxComplete = std::max(std::max(left.maxComplete, right.maxComplete), ret.heightComplete);
	return ret;
}

void resuelveCaso() {
	bintree<char> t;
	t = leerArbol('.');

	std::cout << biggerTree(t).maxComplete << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}