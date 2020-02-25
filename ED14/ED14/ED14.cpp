#include <iostream>
#include <string>

#include "Reorder.h"

/*
Miguel Peñalver Carvajal

En este problema recibimos una serie de carácteres, los cuales debemos ordenar según una serie de
criterios descritos en el enunciado.
*/

bool resuelveCaso() {
	Reorder<char> list;
	std::string cad;

	std::getline(std::cin, cad);
	if (std::cin.fail()) return false;

	list = list.reorder1(cad);
	list.reorder2();
	std::cout << list;

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}