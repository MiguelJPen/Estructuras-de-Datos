#include <iostream>

#include "isBinarySearch.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema devolvemos si un �rbol binario es de b�squeda o no.
El coste de la operaci�n es lineal, pues recorremos el �rbol nodo a nodo, �nicamente pasando una vez por
cada uno de ellos, mediante recursi�n.
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