#include <iostream>
#include <set>
#include <string>

#include "AutoEcuela.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema creamos una aplicación para la gestión de alumnos de la autoescuela.
*/

void mostrar(std::set<tAlumno> const& s, int const& n) { // O(MAP)
	for(tAlumno a : s) {
		if (a.getP() >= n) std::cout << a.getA() << '\n';
	}
}

bool resuelveCaso() {
	std::string orden, al, prof;
	int p;
	std::cin >> orden;
	if (std::cin.fail())
		return false;

	autoEscuela A;

	while (orden != "FIN") {
		try {
			if (orden == "alta") {
				std::cin >> al >> prof;
				A.alta(al, prof);
			}
			else if (orden == "es_alumno") {
				std::cin >> al >> prof;
				if (A.esAlumno(al, prof)) std::cout << al << " es alumno de " << prof;
				else std::cout << al << " no es alumno de " << prof;
				std::cout << '\n';
			}
			else if (orden == "puntuacion") {
				std::cin >> al;
				int n = A.puntuacion(al);
				std::cout << "Puntuacion de " << al << ": " << n << '\n';
			}
			else if (orden == "actualizar") {
				std::cin >> al >> p;
				A.actualizar(al, p);
			}
			else if (orden == "examen") {
				std::cin >> prof >> p;
				std::cout << "Alumnos de " << prof << " a examen:\n";
				mostrar(A.examen(prof, p), p);
			}
			else if (orden == "aprobar") {
				std::cin >> al;
				A.aprobar(al);
			}
		}
		catch (std::domain_error e) {
			std::cout << "ERROR\n";
		}
		std::cin >> orden;
	}
	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}