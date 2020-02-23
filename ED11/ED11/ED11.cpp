#include <iostream>

#include "Mixer.h"

void resuelveCaso() {
	Mixer<long int> list, list2;
	long int aux;

	std::cin >> aux;
	while (aux != 0) {
		list.push(aux);
		std::cin >> aux;
	}
	std::cin >> aux;
	while (aux != 0) {
		list2.push(aux);
		std::cin >> aux;
	}

	list.mix(list2);
	std::cout << list;
}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i)
		resuelveCaso();
	return 0;
}