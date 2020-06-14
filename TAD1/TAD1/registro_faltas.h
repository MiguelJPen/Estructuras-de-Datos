#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#define clave first
#define valor second

using alumno = std::string;
using falta = std::string;

class registro_faltas {
	using info_alumno = std::pair<int, std::unordered_map<falta, int>>;
	std::map<alumno, info_alumno> tablaA;

	using info_falta = std::map<alumno, int>;
	std::unordered_map<falta, info_falta> tablaF;

	// A: número de alumnos
	// F: número de tipos de falta distintos
	// MA: número máximo de alumnos que han cometido una falta
	// MF: número máximo de faltas distintas que ha cometido un alumno
public:
	registro_faltas() {}

	void registrar(falta const& f, alumno const& a) { //O(log A)
		auto & info = tablaA[a];
		++info.first;
		++info.second[f];

		++tablaF[f][a];
	}

	void borrar_falta(falta const& f, alumno const& a) { // O(log A)
		auto itA = tablaA.find(a);
		if (itA != tablaA.end()) {
			auto & info = itA->valor;
			auto itF = info.second.find(f);
			if (itF != info.second.end()) {
				info.first -= itF->valor;
				if (info.first == 0) {
					tablaA.erase(itA);
				}
				else info.second.erase(itF);

				tablaF[f].erase(a);
			}
		}
	}

	void borrar(alumno const& a) { // O(log A + MF log MA)
		auto itA = tablaA.find(a);
		if (itA != tablaA.end()) {
			for (auto f : itA->valor.second)
				tablaF[f.clave].erase(a);
			tablaA.erase(itA);
		}
	}

	int cantidad_falta(falta const& f, alumno const& a) const { // O(log A)
		auto itA = tablaA.find(a);
		if (itA != tablaA.end()) {
			auto & info = itA->valor;
			auto itF = info.second.find(f);
			if (itF != info.second.end())
				return itF->valor;
		}
		return 0;
	}

	int cantidad(alumno const& a) const { // O(log A)
		auto itA = tablaA.find(a);
		if (itA != tablaA.end()) {
			return itA->valor.first;
		}
		return 0;
	}

	std::vector<alumno> lista_negra_falta(falta const& f, int n) const { // O(MA)
		std::vector<alumno> ret;

		auto itF = tablaF.find(f);
		if (itF != tablaF.end()) {
			for (auto par : itF->valor) {
				if (par.valor >= n)
					ret.push_back(par.clave);
			}
		}

		return ret;
	}

	std::vector<alumno> lista_negra(int n) const { // O(A)
		std::vector<alumno> ret;

		for (auto const& par : tablaA) {
			if (par.valor.first >= n)
				ret.push_back(par.clave);
		}
		return ret;
	}
};