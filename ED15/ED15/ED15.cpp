#include <iostream>
#include <set>

#include "queue_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema, dada una lista de sobres y un número determinado de sobres a repartir,
devolvemos una lista con el mayor sobre del montón que cogeríamos si vamos cogiendo 
el número de sobres que necesitamos de manera seguida del montón.
El coste de este programa es lineal respecto al número de sobres.
*/

bool resuelveCaso() {
	long int nSobres, nComensales, i, aux;
	std::cin >> nSobres >> nComensales;
	if (nSobres == 0) return false;

	queue<long int> sobres;
	// Uso multiset por ser un conjunto ordenado en el que puedo usar un iterador.
	std::multiset<long int, std::greater<long int>> seleccionados;

	for (i = 0; i < nComensales; ++i) {
		std::cin >> aux;
		sobres.push(aux);
		seleccionados.insert(aux);
	}
	// Le resto uno al iterador para que me de la primera posición (el mayor elemento).
	std::cout << *seleccionados.begin() << " ";
	for (; i < nSobres; ++i) {
		auto it = seleccionados.find(sobres.front());
		if (it != seleccionados.end()) seleccionados.erase(it);
		sobres.pop();

		std::cin >> aux;
		seleccionados.insert(aux);
		sobres.push(aux);
		std::cout << *seleccionados.begin() << " ";
	}
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}