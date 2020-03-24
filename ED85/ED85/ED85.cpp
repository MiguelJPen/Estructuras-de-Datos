#include <iostream>
#include <vector>

#include "lowerB.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema implmentamos un la funci�n lower_bound para set.
Por la implementaci�n de la funci�n con el iterador, esta tiene complejidad lineal.
*/

bool resuelveCaso() {
	int nElems, aux;
	std::cin >> nElems;
	if (nElems == 0) return false;
	lowerB<long int> conj;


	while (nElems--) {
		std::cin >> aux;
		conj.insert(aux);
	}
	std::cin >> nElems;
	while (nElems--) {
		std::cin >> aux;
		std::pair<bool, long int> p = conj.lower_bound(aux);
		if (!p.first) std::cout << "NO HAY\n";
		else std::cout << p.second << '\n';
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}