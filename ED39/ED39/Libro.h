#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <map>
#include <list>

// NV: número de cantidades distintas de venta de libros.

using Libro = std::string;

class ventaLibro {
private:
	std::unordered_map<Libro, int> ejemplares;
	std::unordered_map<Libro, int> ventas;
	std::map<int, std::list<Libro>> vendidos;
	std::unordered_map<Libro, std::list<Libro>::iterator> inVendidos;

public:
	void nuevoLibro(int const n, Libro const& l) { // O(1)
		ejemplares[l] += n;
	}
	void comprar(Libro const& l) { // O(log(NV))
		if (ejemplares.count(l) == 0) throw std::invalid_argument("Libro no existente");
		if (ejemplares[l] == 0) throw std::out_of_range("No hay ejemplares");
		--ejemplares[l];
		
		if (ventas[l] != 0)
			vendidos[ventas[l]].erase(inVendidos[l]);
		++ventas[l];
		vendidos[ventas[l]].push_front(l);
		inVendidos[l] = vendidos[ventas[l]].begin();
	}
	bool estaLibro(Libro const& l) { // O(1)
		return ejemplares.count(l) != 0;
	}
	void elimLibro(Libro const& l) { // O(log(NV))
		if (ejemplares.count(l) > 0) {
			ejemplares.erase(l);

			if (ventas.count(l) != 0) {
				vendidos[ventas[l]].erase(inVendidos[l]);
				inVendidos.erase(l);
				ventas.erase(l);
			}
		}
	}
	int numEjemplares(Libro const& l) { // O(log(NV))
		if (ejemplares.count(l) == 0) throw std::invalid_argument("No existe el libro " + l + " en el sistema");
		return ejemplares[l];
	}
	std::list<Libro> top10() { // O(1)
		int i = 0;
		auto it = vendidos.rbegin();
		std::list<Libro> ret;

		while (it != vendidos.rend() && i != 10) {
			auto it1 = it->second.begin();
			while (it1 != it->second.end() && i != 10) {
				ret.push_back(*it1);
				++it1;
				++i;
			}
			++it;
		}
		return ret;
	}
};