#include <iostream>
#include <fstream>

#include "carnet_puntos.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema hacemos un programa de gestión de puntos para cada DNI.
*/

bool resuelveCaso() {
	std::string orden, DNI;
	int points;

	std::cin >> orden;
	if (std::cin.fail()) {
		return false;
	}
	carnet_puntos L;

	while (orden != "FIN") {
		try {
			if (orden == "nuevo") {
				std::cin >> DNI;
				L.nuevo(DNI);
			}
			else if (orden == "quitar") {
				std::cin >> DNI >> points;
				L.quitar(DNI, points);
			}
			else if (orden == "consultar") {
				std::cin >> DNI;
				int i = L.consultar(DNI);
				std::cout << "Puntos de " << DNI << ": " << i << '\n';
			}
			else if (orden == "cuantos_con_puntos") {
				std::cin >> points;
				int i = L.cuantos_con_puntos(points);
				std::cout << "Con " << points << " puntos hay " << i << '\n';
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR: " << e.what() << '\n';
		}
		std::cin >> orden;
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}