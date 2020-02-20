#include <iostream>

#include "Inverter.h"

bool resuelveCaso() {
	int aux;
	Inverter<int> list;

	std::cin >> aux;
	if (std::cin.fail()) return false;
	while (aux != 0) {
		list.push_back(aux);
		std::cin >> aux;
	}

	list.invert();
	list.print();
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}