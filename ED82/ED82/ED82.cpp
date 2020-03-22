#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema contamos el número de tramos navegables que tiene un río.
El coste de este algoritmo es lineal respecto al número de nodos del árbol.
*/

typedef struct {
	int caudal, numNavegable;
}tRio;

tRio riosNavegables(bintree<int> const& t) {
	if (t.empty()) return { 0, 0 };
	if (t.left().empty() && t.right().empty()) return { 1, 0 };

	tRio left = riosNavegables(t.left()), right = riosNavegables(t.right()), ret;
	ret.numNavegable = left.numNavegable + right.numNavegable;
	ret.caudal = std::max(left.caudal + right.caudal - t.root(), 0);
	// En este punto, si es la raíz, podemos añadir un tramo extra a los tramos navegables.
	if (ret.caudal > 2) ++ret.numNavegable;
	return ret;
}

void resuelveCaso() {
	bintree<int> t;
	t = leerArbol(-1);

	tRio ret = riosNavegables(t);
	// Por la estructura de la recursión, a veces contamos la raíz, para ello se la descontamos aquí.
	std::cout << (ret.caudal > 2 ? ret.numNavegable - 1 : ret.numNavegable) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}