#include <iostream>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema devolvemos la altura del árbol completo más grande.
El coste de este algoritmo es lineal respecto al número de nodos del árbol.
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