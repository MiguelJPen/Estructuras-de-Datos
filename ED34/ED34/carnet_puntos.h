#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using DNI = std::string;

class carnet_puntos {
private:
	std::unordered_map<DNI, int> list;
	std::vector<int> points = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

public:
	void nuevo(DNI const n) { // O(1), tiene coste constante amortizado por la función insert.
		auto it = list.find(n);
		if (it != list.end())
			throw std::domain_error("Conductor duplicado");
		else {
			list.insert({ n, 15 });
			++points[15];
		}
	}
	void quitar(DNI const n, int const p) { // O(1) por la función find.
		auto it = list.find(n);
		if (it == list.end())
			throw std::domain_error("Conductor inexistente");
		else {
			--points[it->second];
			it->second = std::max(it->second - p, 0);
			++points[it->second];
		}
	}
	int consultar(DNI const n) { // O(1) por la función find.
		auto it = list.find(n);
		if (it == list.end())
			throw std::domain_error("Conductor inexistente");

		return it->second;
	}
	int cuantos_con_puntos(int const p) { // O(1) ya que accedemos a una posición del vector.
		if (p < 0 || p > 15) throw std::domain_error("Puntos no validos");

		return points[p];
	}
};