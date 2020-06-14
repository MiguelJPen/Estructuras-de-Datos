#include <iostream>
#include <string>

#include "Avisos.h"
#include "Time.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema hacemos un programa que controla las consultas de datos de una central nuclear.
*/

bool resuelveCaso() {
	long int n, m;

	std::cin >> n >> m;
	if (std::cin.fail()) return false;

	std::string aviso;
	Time t;
	Avisos a;

	while (n--) {
		std::cin >> aviso >> t;
		a.annadir(aviso, t);
	}
	while (m--) {
		std::cin >> aviso >> n;
		try {
			t = a.consultar(aviso, n);
			std::cout << t << " ";
		}
		catch (std::exception& e) {
			std::cout << "-- ";
		}
	}
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}