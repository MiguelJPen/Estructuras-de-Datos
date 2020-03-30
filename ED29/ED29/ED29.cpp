#include <iostream>
#include <algorithm>
#include <map>

/*
Miguel Jes�s Pe�alver Carvajal

En este problema recibimos una lista de cap�tulos emitidos por una cadena de TV y
devolvemos el mayor n�mero de cap�tulos seguidos que se han emitido distintos.
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