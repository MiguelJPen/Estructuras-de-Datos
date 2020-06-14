#include <iostream>
#include <string>
#include <vector>

#include "consultorio.h"
#include "Date.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema realizo un sistema de gestión de consultas médicas.
*/

bool resuelveCaso() {
	std::string orden, med, pac;
	int day, n;
	Date t;

	std::cin >> n;
	if (std::cin.fail()) return false;

	consultorio H;

	while (n--) {
		std::cin >> orden;
		try {
			if (orden == "nuevoMedico") {
				std::cin >> med;
				H.nuevoMedico(med);
			}
			else if (orden == "pideConsulta") {
				std::cin >> pac >> med >> t;
				H.pideConsulta(pac, med, t);
			}
			else if (orden == "siguientePaciente") {
				std::cin >> med;
				pac = H.siguientePaciente(med);
				std::cout << "Siguiente paciente doctor " << med << '\n' << pac << '\n';
			}
			else if (orden == "atiendeConsulta") {
				std::cin >> med;
				H.atiendeConsulta(med);
			}
			else if (orden == "listaPacientes") {
				std::cin >> med >> day;
				std::list<std::pair<std::string, Date>> l = H.listaPaciente(med, day);
				std::cout << "Doctor " << med << " dia " << day << '\n';
				for (std::pair<std::string, Date> p : l) std::cout << p.first << ' ' << p.second << '\n';
			}
		}
		catch (std::domain_error e) {
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