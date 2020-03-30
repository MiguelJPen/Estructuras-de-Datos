#include <iostream>

#include "Alumno.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos una lista de nombre y si los ejercicios son correctos o no.
Devolvemos una lista ordenada por los nombres y con su nota (distinta de 0).
*/

bool resuelveCaso() {
	int nAlumnos;
	Alumnos eval;
	std::string nombre, correc;
	std::cin >> nAlumnos;
	if (nAlumnos == 0) return false;

	// Para pasar a la siguiente línea
	std::getline(std::cin, nombre);
	while (nAlumnos--) {
		std::getline(std::cin, nombre);
		std::getline(std::cin, correc);
		eval.annadir(nombre, correc);
	}
	eval.mostrarNotas();

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}