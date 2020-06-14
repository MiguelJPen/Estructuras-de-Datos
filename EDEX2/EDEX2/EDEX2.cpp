#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

/*
Luis Ariza López y Miguel Peñalver Carvajal

En este problema realizamos un programa en el que recibimos el número
de noches que un abuelito jugó a distintos juegos de mesa y una lista con 
los juegos que ha jugado ordenados.

Disponemos de una mapa desordenado en el que tenemos como clave el nombre del juego 
y como valor un vector asociado en el que introducimos las noches (un número que para
la primera noche es 1).

Para cada juego leído lo añadimos al mapa en caso de que no exista y añadimos 
al final del vector asociado la noche en la que lo ha jugado usando la 'i' del
bucle 'for'.

A la hora de consultar los datos, primeramente comprobamos que dicho juego 
exista en el mapa, si no existe devolvemos 'NO JUEGA', al igual que si estamos
consultando una vez que ha jugado y que nunca llegó a jugar. En caso de que
sí haya jugado esa vez al juego, devolvemos la noche en la que jugó.
*/

using game = std::string;

bool resuelveCaso() {
	std::unordered_map<game, std::vector<int>> daysPlayed;
	std::string played;
	int days, questions, index;

	std::cin >> days;
	if (std::cin.fail()) return false;

	for (int i = 1; i <= days; ++i) { // O(n) siendo n el número de días que juega, 
		// ya que la inserción en el mapa (en caso de que no haya jugado nunca a ese juego)
		// y la inserción de un nuevo elemento al vector son O(1).

		std::cin >> played;
		daysPlayed[played].push_back(i);
	}

	std::cin >> questions;

	for (int i = 0; i < questions; ++i) { // O(m) siendo m el número de preguntas realizadas.
		// El coste de las operaciones realizadas en cada vuelta del bucle es O(1), ya que 
		// los accesos al mapa y los accesos al vector tienen O(1).
		std::cin >> index >> played;

		if (daysPlayed.count(played) == 0) std::cout << "NO JUEGA\n";

		else {
			if (daysPlayed[played].size() < index)
				std::cout << "NO JUEGA\n";
			else std::cout << daysPlayed[played].at(index - 1) << '\n';
		}
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}