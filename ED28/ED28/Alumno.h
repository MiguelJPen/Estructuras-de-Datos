#pragma once

#include <iostream>
#include <string>
#include <map>

/*
Miguel Jesús Peñalver Carvajal

He implementado una lista ordenada porque una persona puede hacer varios ejercicios y
para poder mostrar la lista ordenada con complejidad lineal.
*/

using alumno = std::string;

class Alumnos {
private: 
	std::map<alumno, int> list;
public:
	void annadir(alumno const& a, std::string const& correct) { // O(log n)
		if (correct == "CORRECTO")
			++list[a];
		else --list[a];
	}
	void mostrarNotas() { // O(n)
		for (auto const& par : list)
			if (par.second != 0)
				std::cout << par.first << ", " << par.second << '\n';
		std::cout << "---\n";
	}
};