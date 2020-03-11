#include <iostream>

#include "Border.h"
#include <vector>

/*
Miguel Jesús Peñalver Carvajal

En este problema, con la clase Border extendemos la clase bintree y creamos una función para calcular
la frontera, que es devuelta en un vector de enteros. El coste de la operación es lineal en el número
de nodos del árbol.
*/

void resuelveCaso() {
	Border<int> t = readTree(-1);
	std::vector<int> border = t.calculateBorder();

	for (int i : border)
		std::cout << i << ' ';
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}