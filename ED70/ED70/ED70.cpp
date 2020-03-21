#include <iostream>

#include "Engordar.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema insertamos los elementos de l2 en l1, alternando entre un elemento
al inicio y otro al final.

El coste de este algoritmo es O(n), siendo n el número de elementos de la lista 2.
*/

void resuelveCaso() {
	Engordar<int> l1, l2;
	int nL1, nL2, aux;

	std::cin >> nL1;
	while(nL1--) {
		std::cin >> aux;
		l1.push_back(aux);
	}
	std::cin >> nL2;
	while (nL2--) {
		std::cin >> aux;
		l2.push_back(aux);
	}
	l1.engordar(l2);
	std::cout << l1;
}

int main() {
	int n;
	std::cin >> n;
	while(n--) resuelveCaso();
	return 0;
}