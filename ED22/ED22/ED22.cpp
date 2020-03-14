#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema calculamos, con una función externa a la clase bintree, el diámetro de un árbol.
La función que calcula el diámetro devuelve la mayor altura entre los dos árboles hijos de un nodo
y el diámetro de ellos en un struct.
El coste de esta función es lineal respecto al número de nodos.
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