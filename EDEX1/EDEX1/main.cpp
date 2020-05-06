
// Miguel Jesús Peñalver Carvajal

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

/*
En este problema hallamos el camino más largo de números pares de un árbol.

El coste de este problema es lineal en el número de nodos, ya que para descender en el árbol
hacemos una llamada recursiva por cada hijo. Si el hijo es vacío se devuelve {0, 0}, ya que 
no hay ningún nodo hasta el primer nodo impar y el camino más largo es de longitud 0.
*/

typedef struct {
	int nodosHastaImpar, camino;
} tTreeInfo;

tTreeInfo caminoPares(bintree<int> t) {
	// Caso del árbol vacío.
	if (t.empty()) return { 0, 0 };

	// Analizamos los resultados de los dos subárboles.
	tTreeInfo l = caminoPares(t.left()), r = caminoPares(t.right());

	// Si es par, seguimos contando el máximo camino y añadimos un nodo a la variable 'nodosHastaImpar'.
	if (t.root() % 2 == 0)
		return { max(l.nodosHastaImpar, r.nodosHastaImpar) + 1, max(max(l.camino, r.camino), l.nodosHastaImpar + r.nodosHastaImpar + 1) };

	// Si es impar, el contador de nodos hasta el primer nodo impar se pone a 0 y se calcula el máximo de los caminos de los subárboles.
	return { 0, max(l.camino, r.camino) };
}

void resuelveCaso() {
	bintree<int> arbol = leerArbol(-1);
	cout << caminoPares(arbol).camino << '\n';
}


int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) {
		resuelveCaso();
	}

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
