
#include <iostream>
#include <fstream>

#include "registro_faltas.h"


void mostrar(std::vector<alumno> const& v) {
	for (auto const& a : v) {
		std::cout << a << ' ';
	}
	std::cout << '\n';
}

bool resuelveCaso() {
	std::string orden;
	int num;
	std::cin >> orden;
	if (!std::cin)
		return false;

	registro_faltas B;

	std::string nombre, falta;
	while (orden != "FIN") {
		if (orden == "registrar") {
			std::cin >> falta >> nombre;
			B.registrar(falta, nombre);
		}
		else if (orden == "lista_negra") {
			std::cin >> num;
			mostrar(B.lista_negra(num));
		}
		else if (orden == "lista_negra_falta") {
			std::cin >> falta >> num;
			std::cout << falta << ": ";
			mostrar(B.lista_negra_falta(falta, num));
		}
		else if (orden == "borrar") {
			std::cin >> nombre;
			B.borrar(nombre);
		}
		else if (orden == "borrar_falta") {
			std::cin >> falta >> nombre;
			B.borrar_falta(falta, nombre);
		}
		else if (orden == "cantidad") {
			std::cin >> nombre;
			std::cout << nombre << ": " << B.cantidad(nombre) << '\n';
		}
		else if (orden == "cantidad_falta") {
			std::cin >> falta >> nombre;
			std::cout << nombre << ": " << B.cantidad_falta(falta, nombre) << ' ' << falta << '\n';
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