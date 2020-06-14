#include <iostream>
#include <string>
#include <unordered_map>

#include "Libro.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema hacemos un programa de gestión de libros para un tienda.
*/

bool resuelveCaso() {
	std::string orden, libro;
	int num, n;

	std::cin >> n;
	if (std::cin.fail()) return false;

	ventaLibro v;

	while (n--) {
		std::cin >> orden;
		try {
			if (orden == "nuevoLibro") {
				std::cin >> num;
				std::cin.get();
				std::getline(std::cin, libro);
				v.nuevoLibro(num, libro);
			}
			else if (orden == "comprar") {
				std::cin.get();
				std::getline(std::cin, libro);
				v.comprar(libro);
			}
			else if (orden == "numEjemplares") {
				std::cin.get();
				std::getline(std::cin, libro);
				int i = v.numEjemplares(libro);
				std::cout << "Existen " << i << " ejemplares del libro " << libro << '\n';
			}
			else if (orden == "estaLibro") {
				std::cin.get();
				std::getline(std::cin, libro);
				std::cout << (v.estaLibro(libro) ? "El libro " + libro + " esta en el sistema\n" : "No existe el libro " + libro + " en el sistema\n");
			}
			else if (orden == "elimLibro") {
				std::cin.get();
				std::getline(std::cin, libro);
				v.elimLibro(libro);
			}
			else if (orden == "top10") {
				std::list<std::string> l = v.top10();
				std::cout << "TOP10\n";
				for (std::string s : l) std::cout << "    " << s << '\n';
			}
		}
		catch (std::exception& e) {
			std::cout << e.what() << '\n';
		}

	}
	std::cout << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}