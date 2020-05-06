#ifndef registro_faltas_h
#define registro_faltas_h
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
	map<alumno, info_alumno> tabla;
public:
	registro_faltas() {}

	void registrar(falta const& f, alumno const& a) { //O(log A)
		auto & info = tabla[a];
		++info.first;
		++info.second[f];
	}

	void borrar_falta(falta const& f, alumno const& a) { // O(log A)
		auto itA = tabla.find(a);
		if (itA != tabla.end()) {
			auto & info = itA->valor;
			auto itF = info.second.find(f);
			if (itF != info.second.end()) {
				info.first -= itF->valor;
				if (info.first == 0) {
					tabla.erase(itA);
				}
				else info.second.erase(itF);
			}
		}
	}

	void borrar(alumno const& a) {
		tabla.erase(a);
	}

	int cantidad_falta(falta const& f, alumno const& a) const { // O(log A)
		auto itA = tabla.find(a);
		if (itA != tabla.end()) {
			auto & info = itA->valor;
			auto itF = info.second.find(f);
			if (itF != info.second.end())
				return itF->valor;
		}
		return 0;
	}

	int cantidad(alumno const& a) const { // O(log A)
		auto itA = tabla.find(a);
		if (itA != tabla.end()) {
			return itA->valor.first;
		}
		return 0;
	}

	std::vector<alumno> lista_negra_falta(falta const& f, int n) const {

	}

	std::vector<alumno> lista_negra(int n) const {

	}
};

#endif
