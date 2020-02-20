#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#include "conjunto.h"

using namespace std;

/*
Miguel Peñalver Carvajal y Luis Ariza López

En este programa, que recibe una serie de elementos, devuelve los k elementos mayores.
*/

template <class T>
void resuelve(T centinela) {
	//De acuerdo al enunciado el coste del algoritmo es constante, de orden k
	set<T> cjto;

	// Introducimos los k elementos mayores que buscamos.
	int k;
	cin >> k;
	T elem;

	// Introducimos los elementos y, en caso de que el tamaño del conjunto sea mayor que 'k',
	// borramos el mínimo de los elementos, así siempre tendremos el conjunto con los 'k' elementos
	// mayores.
	cin >> elem;
	while (elem != centinela) {
		cjto.insert(elem);
		if (cjto.size() > k)
			cjto.erase_min();
		cin >> elem;
	}
	cout << cjto.minimo();
	cjto.erase_min();

	while (!cjto.empty()) {
		cout << ' ' << cjto.minimo();
		cjto.erase_min();
	}
	cout << '\n';
}

bool resuelveCaso() {
    char tipo;
    cin >> tipo;
    
    if (!cin)
        return false;
    
    if (tipo == 'N') { // el caso es de números
        resuelve(-1);
    } else { // el caso es de cadenas
        resuelve(string("FIN"));
    }
	return true;
}

int main() {
    while (resuelveCaso());
	return 0;
}
