#include <iostream>

#include "Inverter.h"

/*
Miguel Jes�s Pe�alver Carvajal

Este programa realiza la inversi�n de una lista de n�meros enteros. La clase "Inverter", que hereda de deque,
es la encargada de realizar la inversi�n de la lista y de imprimirla por pantalla.
*/

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