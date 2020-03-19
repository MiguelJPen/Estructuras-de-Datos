#include <iostream>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema devolvemos el número de equipos de rescate necesarios para recoger a los excursionistas y el mayor número 
de rescates que va a realizar un equipo.
El coste de este algoritmo es lineal respecto al número de nodos, ya que pasamos una vez por cada uno.
*/

typedef struct {
	int numRescates, mayorRescate;
} tRescate;

tRescate rescates(bintree<int> const& t) {
	if (t.empty()) return { 0, 0 };

	tRescate iz = rescates(t.left()), der = rescates(t.right()), ret = { 0, 0 };

	ret.numRescates = iz.numRescates + der.numRescates;
	ret.mayorRescate = std::max(iz.mayorRescate, der.mayorRescate) + t.root();
	if (ret.numRescates == 0 && t.root() != 0)
		++ret.numRescates;
	return ret;
}

void resuelveCaso() {
	bintree<int> t;
	t = leerArbol(-1);

	tRescate resc = rescates(t);
	std::cout << resc.numRescates << ' ' << resc.mayorRescate << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}