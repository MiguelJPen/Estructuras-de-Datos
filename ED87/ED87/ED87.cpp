#include <iostream>

#include "set_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema añadimos la función count_interval(low, top) al fichero set_eda.h
El orden de la función en el caso promedio es O(log n) y en el caso peor O(n), siendo 
n el número de elementos en el conjunto.
*/

bool resuelveCaso() {
	long int card, nInter, aux, low, top;
	set<long int> s;

	std::cin >> card >> nInter;
	if (std::cin.fail()) return false;
	while (card--) {
		std::cin >> aux;
		s.insert(aux);
	}
	while (nInter--) {
		std::cin >> low >> top;
		std::cout << s.count_interval(low, top) << '\n';
	}
	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}