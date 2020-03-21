#include <iostream>

#include "Intercambiador.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema extiendo la clase queue para haceruna funci�n
que intercambie los nodos de la cola dos a dos.
El coste de este algoritmo es lineal respecto al n�mero de nodos.
*/

bool resuelveCaso() {
	long long int n, aux;
	Mixer<long long int> l;

	std::cin >> n;
	if (n == 0) return false;
	while (n--) {
		std::cin >> aux;
		l.push(aux);
	}
	l.mix();
	std::cout << l;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}