#include <iostream>

#include "isBinarySearch.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema devolvemos si un árbol binario es de búsqueda o no.
El coste de la operación es lineal, pues recorremos el árbol nodo a nodo, únicamente pasando una vez por
cada uno de ellos, mediante recursión.
*/

void resuelveCaso() {
	isBS<int> t = readTree(-1);

	std::cout << (t.correct() ? "SI" : "NO") << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}