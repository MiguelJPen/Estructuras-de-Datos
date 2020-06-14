#pragma once
#include <string>

class tAlumno {
private: 
	std::string alumno;
	int puntos;

public:
	tAlumno(std::string alumno, int p) {
		this->alumno = alumno;
		this->puntos = p;
	}
	bool operator<(tAlumno const& h) const {
		return alumno < h.alumno;
	}
	bool operator==(tAlumno const& h) const {
		return alumno == h.alumno;
	}
	int getP() {
		return puntos;
	}
	std::string getA() {
		return alumno;
	}
};