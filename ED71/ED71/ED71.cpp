#include <iostream>

#include "Intercambiador.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema extiendo la clase queue para haceruna función
que intercambie los nodos de la cola dos a dos.
El coste de este algoritmo es lineal respecto al número de nodos.
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