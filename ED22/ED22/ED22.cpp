#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema calculamos, con una función externa a la clase bintree, el diámetro de un árbol.
La función que calcula el diámetro devuelve la mayor altura entre los dos árboles hijos de un nodo, 
mientras que almacena el mayor diámetro en una variable que pasamos por referencia, 'diameter'.
El coste de esta función es lineal respecto al número de nodos.
*/

int diam(bintree<char> const& t, int& diameter) {
	if (t.empty()) return 0;
	int left = diam(t.left(), diameter), right = diam(t.right(), diameter);
	diameter = std::max(left + right + 1, diameter);
	return std::max(left + 1, right + 1);
}

void resuelveCaso() {
	bintree<char> t;
	t = leerArbol('.');

	int diameter = 0;
	diam(t, diameter);
	std::cout << diameter << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}