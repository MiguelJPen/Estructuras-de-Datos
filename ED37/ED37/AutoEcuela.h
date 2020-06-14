#include <string>
#include <map>
#include <unordered_map>
#include <set>

#include "tAlumno.h"

using alumno = std::string;
using profesor = std::string;

// MAP: máximo número de alumnos de un profesor.

class autoEscuela {
private:
	std::unordered_map<alumno, profesor> alumnoProf;
	std::unordered_map<alumno, int> alumnoPunt;
	std::unordered_map<profesor, std::set<tAlumno>> listProfesor;

public:
	void alta(alumno const& al, profesor const& prof) { // O(log(MAP))
		if (alumnoProf.count(al) == 0) {
			alumnoProf.insert({ al, prof });
			alumnoPunt[al] = 0;
			listProfesor[prof].insert({ al, 0 });
		}
		else {
			listProfesor[alumnoProf[al]].erase({ al, 0 });
			listProfesor[prof].insert({ al, alumnoPunt[al] });
			alumnoProf[al] = prof;
		}
	}
	bool esAlumno(alumno const& al, profesor const& prof) { // O(1)
		return alumnoProf[al] == prof;
	}
	int puntuacion(alumno const& al) { // O(1)
		if (alumnoPunt.count(al) == 0) throw std::domain_error("El alumno " + al + " no esta matriculado");

		return alumnoPunt[al];
	}
	void actualizar(alumno const& al, int n) { // O(log(MAP))
		if (alumnoPunt.count(al) == 0) throw std::domain_error("El alumno " + al + " no esta matriculado");

		listProfesor[alumnoProf[al]].erase({ al, alumnoPunt[al] });
		alumnoPunt[al] += n;
		listProfesor[alumnoProf[al]].insert({ al, alumnoPunt[al] });
	}
	std::set<tAlumno> examen(profesor const& p, int n) { // O(1)
		return listProfesor[p];
	}
	void aprobar(alumno const& a) { // O(log(MAP))
		if (alumnoPunt.count(a) == 0) throw std::domain_error("El alumno " + a + " no esta matriculado");

		listProfesor[alumnoProf[a]].erase({ a, alumnoPunt[a] });
		alumnoPunt.erase(a);
		alumnoProf.erase(a);
	}
};