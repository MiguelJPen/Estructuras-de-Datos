#include <iostream>
#include <string>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema hallamos si un árbol es completo, semicompleto o no es nada.
El algoritmo tiene complejidad lineal respecto al número de nodos.
*/

typedef struct {
	std::string info;
	int height;
}tInfo;

tInfo completitud(bintree<char> t) {
	if (t.empty()) return { "COMPLETO", 0 };

	tInfo left = completitud(t.left()), right = completitud(t.right());

	if (left.height == right.height && left.info == "COMPLETO" && right.info == "COMPLETO")
		return { "COMPLETO", 1 + left.height };

	if ((left.info != "NADA" && right.info != "NADA") && ((left.height == right.height + 1 && left.info == "COMPLETO") || (left.height == right.height && left.info == "SEMICOMPLETO" && right.info == "COMPLETO")))
		return { "SEMICOMPLETO", 1 + right.height };

	else return { "NADA", 0};
}

void resuelveCaso() {
	bintree<char> t;
	t = leerArbol('.');

	std::cout << completitud(t).info << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}