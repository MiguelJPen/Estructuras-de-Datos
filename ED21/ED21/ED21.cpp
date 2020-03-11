#include <iostream>
#include <string>

#include "Minimum.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema, con la clase Minimum extendemos la clase bintree y creamos una función genérica 
para calcular el mínimo. Esta función tiene coste lineal respecto al número de nodos.
*/

bool resuelveCaso() {
	std::string empty = "#";
	char c;
	std::cin >> c;
	if (std::cin.fail()) return false;
	
	if (c == 'N') {
		Minimum<int> t = readTree(-1);
		std::cout << t.calculateMinimum() << '\n';
	}
	else {
		Minimum<std::string> t = readTree(empty);
		std::cout << t.calculateMinimum() << '\n';
	}
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}