#include <iostream>

#include "set_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema a�adimos la funci�n count_interval(low, top) al fichero set_eda.h
El orden de la funci�n en el caso promedio es O(log n) y en el caso peor O(n), siendo 
n el n�mero de elementos en el conjunto.
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