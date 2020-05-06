
// Miguel Jes�s Pe�alver Carvajal

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "bintree_eda.h"

/*
En este problema hallamos el camino m�s largo de n�meros pares de un �rbol.

El coste de este problema es lineal en el n�mero de nodos, ya que para descender en el �rbol
hacemos una llamada recursiva por cada hijo. Si el hijo es vac�o se devuelve {0, 0}, ya que 
no hay ning�n nodo hasta el primer nodo impar y el camino m�s largo es de longitud 0.
*/

typedef struct {
	int nodosHastaImpar, camino;
} tTreeInfo;

tTreeInfo caminoPares(bintree<int> t) {
	// Caso del �rbol vac�o.
	if (t.empty()) return { 0, 0 };

	// Analizamos los resultados de los dos sub�rboles.
	tTreeInfo l = caminoPares(t.left()), r = caminoPares(t.right());

	// Si es par, seguimos contando el m�ximo camino y a�adimos un nodo a la variable 'nodosHastaImpar'.
	if (t.root() % 2 == 0)
		return { max(l.nodosHastaImpar, r.nodosHastaImpar) + 1, max(max(l.camino, r.camino), l.nodosHastaImpar + r.nodosHastaImpar + 1) };

	// Si es impar, el contador de nodos hasta el primer nodo impar se pone a 0 y se calcula el m�ximo de los caminos de los sub�rboles.
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
