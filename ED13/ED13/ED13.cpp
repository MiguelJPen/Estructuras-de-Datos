#include <iostream>

#include "deque_eda.h"

/*
Miguel Peñalver Carvajal

En este problema recibimos una lista ordenada por valores absolutos y la devolvemos ordenada según
los valores de los elementos.
*/

bool resuelveCaso() {
	deque<int> list;
	int n, aux;

	std::cin >> n;
	if (n == 0) return false;

	// En la lectura de la lista la llenamos por la parte frontal o trasera, según sea positivo
	// o negativo el elemento leído.
	for (int i = 0; i < n; ++i) {
		std::cin >> aux;
		if (aux > 0)
			list.push_back(aux);
		else list.push_front(aux);
	}

	while (!list.empty()) {
		std::cout << list.front() << ' ';
		list.pop_front();
	}
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}