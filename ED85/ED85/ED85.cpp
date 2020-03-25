#include <iostream>
#include <vector>

#include "set_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema implmentamos un la funci�n lower_bound para set.
He modificado el archivo set_eda.h para implementar dicha funci�n y poder acceder a ciertos 
campos internos, como los nodos del �rbol. La funci�n tiene complejidad logar�tmica respecto
al n�mero de elementos de 'set'.
*/

bool resuelveCaso() {
	int nElems, aux;
	std::cin >> nElems;
	if (nElems == 0) return false;
	set<long int> conj;


	while (nElems--) {
		std::cin >> aux;
		conj.insert(aux);
	}
	std::cin >> nElems;
	while (nElems--) {
		std::cin >> aux;
		std::pair<bool, long int> p = conj.lower_bound(aux);
		if (!p.first) std::cout << "NO HAY\n";
		else std::cout << p.second << '\n';
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}