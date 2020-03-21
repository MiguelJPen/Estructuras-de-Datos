#include <iostream>

#include "Eliminator.h"
#include "Time.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema extendemos la clase queue para hacer una función que elimine las posiciones
pares de la cola.
El coste de este algoritmo es lineal respecto al número de elementos de la cola.
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