#include <iostream>
#include <algorithm>
#include <map>

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos una lista de capítulos emitidos por una cadena de TV y
devolvemos el mayor número de capítulos seguidos que se han emitido distintos.
*/

void resuelveCaso() {
	int nElems, aux, max = 0, lastRepeatedIndex = 0;
	std::map<int, int> emited;
	std::cin >> nElems;

	for (int i = 0; i < nElems; ++i) {
		std::cin >> aux;
		if (emited.count(aux) == 1)
			lastRepeatedIndex = std::max(emited[aux] + 1, lastRepeatedIndex);
		emited[aux] = i;
		max = std::max(i - lastRepeatedIndex + 1, max);
	}
	std::cout << max << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}