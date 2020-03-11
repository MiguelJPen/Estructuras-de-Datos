#include <iostream>

#include "TreeData.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema, con la clase TreeData extendemos la clase bintree y creamos tres funciones para calcular la altura,
las hojas y los nodos de un árbol binario.
*/

void resuelveCaso() {
	TreeData<char> t = readTreeData('.');

	std::cout << t.nodes() << ' ' << t.leaves() << ' ' << t.height() << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}