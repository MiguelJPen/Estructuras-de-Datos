#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <list>

using DNI = std::string;

// N: número total de DNIs.
// MP: máximo número de DNIs con un número determinado de puntos.

class carnet_puntos {
private:
	std::unordered_map<DNI, int> list;

	std::unordered_map<DNI, std::list<DNI>::iterator> listP; // Iteradores de cada DNI en la lista ordenada para eliminarlos
	std::vector<std::list<DNI>> listO; // Lista ordenada con los DNI

public:
	carnet_puntos() {
		listO.resize(16);
	}
	void nuevo(DNI const n) { // O(1) por ser todas las operaciones constantes.
		auto it = list.find(n);
		if (it != list.end())
			throw std::domain_error("Conductor duplicado");
		
		list.insert({ n, 15 });

		listO[15].push_front(n);
		listP.insert({ n, listO[15].begin() });
	}
	void quitar(DNI const n, int const p) { // O(1) por ser todas las operaciones constantes.
		auto it = list.find(n);
		if (it == list.end())
			throw std::domain_error("Conductor inexistente");
		
		if (it->second != 0) {
			listO[it->second].erase(listP.at(n));

			it->second = std::max(it->second - p, 0);

			listO[it->second].push_front(n);
			listP[n] = listO[it->second].begin();
		}
	}
	void recuperar(DNI const n, int const p) { // O(1) por ser todas las operaciones constantes.
		auto it = list.find(n);
		if (it == list.end())
			throw std::domain_error("Conductor inexistente");
		
		if (it->second != 15) {
			listO[it->second].erase(listP.at(n));

			it->second = std::min(it->second + p, 15);

			listO[it->second].push_front(n);
			listP[n] = listO[it->second].begin();
		}
	}
	int consultar(DNI const n) { // O(1) por ser todas las operaciones constantes.
		auto it = list.find(n);
		if (it == list.end())
			throw std::domain_error("Conductor inexistente");

		return it->second;
	}
	int cuantos_con_puntos(int const p) { // O(1).
		if (p < 0 || p > 15) throw std::domain_error("Puntos no validos");

		return listO[p].size();
	}
	std::list<DNI> lista_por_puntos(int const p) { // O(1).
		if (p < 0 || p > 15) throw std::domain_error("Puntos no validos");

		return listO[p];
	}
};