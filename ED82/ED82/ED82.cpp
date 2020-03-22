#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema contamos el n�mero de tramos navegables que tiene un r�o.
El coste de este algoritmo es lineal respecto al n�mero de nodos del �rbol.
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
	// En este punto, si es la ra�z, podemos a�adir un tramo extra a los tramos navegables.
	if (ret.caudal > 2) ++ret.numNavegable;
	return ret;
}

void resuelveCaso() {
	bintree<int> t;
	t = leerArbol(-1);

	tRio ret = riosNavegables(t);
	// Por la estructura de la recursi�n, a veces contamos la ra�z, para ello se la descontamos aqu�.
	std::cout << (ret.caudal > 2 ? ret.numNavegable - 1 : ret.numNavegable) << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}