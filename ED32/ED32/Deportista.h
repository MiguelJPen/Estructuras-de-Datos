#pragma once

#include <algorithm>
#include <vector>
#include <map>
#include <set>

#include "Sport.h"

/*
Miguel Jesús Peñalver Carvajal
*/

using deportista = std::string;
using deporte = std::string;

class Deportista {
private:
	std::map<deportista, deporte> listado;
	std::map<deporte, int> listaConDeporte;
public:
	void annadir(deportista const& person, deporte const& depo) { // O(log(nk)) siendo n el número de deportistas y k el número  de deportes.
		if (person == "") {
			listaConDeporte[depo];
			return;
		}
		if (listado.count(person) == 1 && listado[person] != depo) {
			if (listado[person] != "NO ADMITIDO")
				listaConDeporte[listado[person]] = std::max((listaConDeporte[listado[person]] - 1), 0);
			listado[person] = "NO ADMITIDO";
		}
		else if (listado.count(person) == 0) {
			listado[person] = depo;
			++listaConDeporte[depo];
		}
	}
	void mostrarDeporte() { // O(n)
		std::set<Sport> conj;

		auto it = listaConDeporte.begin();
		while (it != listaConDeporte.end()) {
			conj.insert(Sport(it->first, it->second));
			++it;
		}

		auto itSet = conj.begin();
		while (itSet != conj.end()) {
			std::cout << *itSet << '\n';
			++itSet;
		}
		std::cout << "---\n";
	}
};