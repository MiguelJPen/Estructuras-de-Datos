#include <iostream>

#include "Polynomial.h"
/*
Miguel Pe�alver Carvajal

En este problema leemos un polinomio y devolvemos la valoraci�n de dicho polinomio para ciertos valores.
*/
bool resuelveCaso() {

	try {
		// In the constructor we read the polinomy.
		Polynomial pol;
		int nValue, aux;

		std::cin >> nValue;
		for (int i = 0; i < nValue; ++i) {
			std::cin >> aux;
			// We calculate the value of the polinomy for a certain constant (aux).
			std::cout << pol.valoration(aux) << '\n';
		}
	}
	catch (domain_error &e) {
		return false;
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}