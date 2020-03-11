#include <iostream>

#include "Border.h"
#include <vector>

/*
Miguel Jes�s Pe�alver Carvajal

En este problema, con la clase Border extendemos la clase bintree y creamos una funci�n para calcular
la frontera, que es devuelta en un vector de enteros. El coste de la operaci�n es lineal en el n�mero
de nodos del �rbol.
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