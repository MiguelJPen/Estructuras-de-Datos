#include <iostream>

#include "Eliminator.h"
#include "Time.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema extendemos la clase queue para hacer una funci�n que elimine los elementos
estrictamente menores que los anteriores.
El coste de este algoritmo es lineal respecto al n�mero de elementos de la cola.
*/

bool resuelveCaso() {
	Eliminator <Time> l;
	Time aux;
	int n;

	std::cin >> n;
	if (n == 0) return false;
	while (n--) {
		std::cin >> aux;
		l.push(aux);
	}
	l.eliminate();
	std::cout << l;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}