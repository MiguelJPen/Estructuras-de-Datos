#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema calculamos, con una funci�n externa a la clase bintree, el di�metro de un �rbol.
La funci�n que calcula el di�metro devuelve la mayor altura entre los dos �rboles hijos de un nodo
y el di�metro de ellos en un struct.
El coste de esta funci�n es lineal respecto al n�mero de nodos.
*/

typedef struct {
	int height, diameter;
} tTreeInfo;

tTreeInfo diam(bintree<char> const& t) {
	if (t.empty()) return { 0, 0 };
	tTreeInfo l = diam(t.left()), r = diam(t.right());
	return { std::max(l.height, r.height) + 1, std::max(std::max(l.diameter, r.diameter), l.height + r.height + 1)};
}

void resuelveCaso() {
	bintree<char> t;
	t = leerArbol('.');
	std::cout << diam(t).diameter << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}