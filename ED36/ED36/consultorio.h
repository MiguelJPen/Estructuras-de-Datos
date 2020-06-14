#pragma once

#include <string>
#include <list>
#include <unordered_map>
#include <map>
#include <vector>

#include "Date.h"

/*
Miguel Jes�s Pe�alver Carvajal
*/

// HM: n�mero m�ximo de horas ocupadas de un m�dico.
// HDM: n�mero m�ximo de horas ocupadas en un d�a de un m�dico.

using medico = std::string;
using paciente = std::string;

class consultorio {
	// Almacenamos las consultas en un mapa con clave el nombre del m�dico y como valor un mapa 
	// ordenado con la fecha y el nombre del paciente.
	std::unordered_map<medico, std::map<Date, paciente>> consultas;
	// En este mapa guardamos, para cada m�dico un mapa con cada d�a y �ste contiene un puntero al primer 
	// paciente de dicho d�a.
	std::unordered_map<medico, std::unordered_map<int, std::map<Date, paciente>::iterator>> inConsulta;

public:
	void nuevoMedico(medico const& med) { // O(1)
		if (consultas.count(med) == 0) {
			consultas.insert({ med, {} });
			inConsulta.insert({ med, {} });
		}
	}
	void pideConsulta(paciente const& pac, medico const& med, Date const& t) { // O(log(HM))
		if (consultas.count(med) == 0) throw std::domain_error("Medico no existente");
		if (consultas[med].count(t) != 0) throw std::domain_error("Fecha ocupada");

		consultas[med].insert({ t, pac });
		if (inConsulta[med].count(t.day()) == 0 || t < inConsulta[med][t.day()]->first)
			inConsulta[med][t.day()] = consultas[med].find(t);
	}
	std::string siguientePaciente(medico const& med) { // O(1)
		if (consultas.count(med) == 0) throw std::domain_error("Medico no existente");
		if (consultas[med].size() == 0) throw std::domain_error("No hay pacientes");

		return consultas[med].begin()->second;
	}
	void atiendeConsulta(medico const& med) { // O(log(HM))
		if (consultas.count(med) == 0) throw std::domain_error("Medico no existente");
		if (consultas[med].size() == 0) throw std::domain_error("No hay pacientes");

		int firstDay = consultas[med].begin()->first.day();
		auto it = consultas[med].begin();
		++it;
		// Si es distinto del �ltimo de la lista (evitar excepciones) o el siguiente d�a es distinto, eliminamos esa posici�n del mapa.
		if (it == consultas[med].end() || firstDay != it->first.day())
			inConsulta[med].erase(firstDay);
		// Si no es el final de la lista y el siguiente tiene el mismo d�a.
		else if (it != consultas[med].end() && firstDay == it->first.day())
			inConsulta[med][it->first.day()] = it;
		consultas[med].erase(consultas[med].begin());
	}
	std::list<std::pair<std::string, Date>> listaPaciente(medico const& med, int day) { // O(HDM)
		if (consultas.count(med) == 0) throw std::domain_error("Medico no existente");

		std::list<std::pair<std::string, Date>> ret;

		if (inConsulta[med].count(day) != 0) {
			auto it = inConsulta[med][day];
			while (it != consultas[med].end() && it->first.day() == day) {
				ret.push_back(std::make_pair(it->second, it->first));
				++it;
			}
		}
		return ret;
	}
};