#include <iostream>
#include <string>

#include "Deportista.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos unas listas de deportes con gente que se ha apuntado, y devolvemos 
el número de gente apuntada por deportes, en una lista ordenada, teniendo en cuenta que la misma
persona solo se puede apuntar a un deporte.
*/

bool resuelveCaso() {
	std::string deporte, nickname;
	Deportista list;

	std::cin >> nickname;
	if (std::cin.fail()) return false;
	while (nickname != "_FIN_") {

		if (nickname[0] >= 'A' && nickname[0] <= 'Z') {
			deporte = nickname;
			nickname = "";
		}
		list.annadir(nickname, deporte);
		std::cin >> nickname;
	}
	list.mostrarDeporte();

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}