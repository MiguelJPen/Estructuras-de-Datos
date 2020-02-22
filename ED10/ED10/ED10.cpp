#include <iostream>

#include "Inserter.h"

/*
Miguel Peñalver Carvajal

En este problema introducimos una lista dentro de otra a partir de una posición dada. Las listas
utilizadas son las listas enlazadas.
*/

bool resuelveCaso() {
	int nList, nList2, pos, aux;
	Inserter<int> list, list2;

	// Número de elementos de la lista principal.
	std::cin >> nList;
	if (std::cin.fail()) return false;
	for (int i = 0; i < nList; ++i) {
		std::cin >> aux;
		list.push(aux);
	}
	// Introducimos el número de elementos de la lista secundaria y la posición a partir de la cual la
	// vamos a introducir.
	std::cin >> nList2 >> pos;
	for (int i = 0; i < nList2; ++i) {
		std::cin >> aux;
		list2.push(aux);
	}
	list.insert(list2, pos);
	std::cout << list;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}