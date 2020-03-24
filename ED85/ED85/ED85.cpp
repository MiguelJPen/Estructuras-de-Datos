#include <iostream>
#include <vector>

#include "lowerB.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema implmentamos un la función lower_bound para set.
Por la implementación de la función con el iterador, esta tiene complejidad lineal.
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