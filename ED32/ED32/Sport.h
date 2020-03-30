#pragma once

#include <iostream>
#include <string>

class Sport {
private:
	int alumnos;
	std::string sport;

public:
	Sport(std::string sport, int a) {
		alumnos = a;
		this->sport = sport;
	}
	bool operator< (Sport const& s) const {
		return (this->alumnos > s.alumnos || (this->alumnos == s.alumnos && this->sport.compare(s.sport) < 0));
	}
	bool operator> (Sport const& s) const {
		return (this->alumnos < s.alumnos || (this->alumnos == s.alumnos && this->sport.compare(s.sport) > 0));
	}
	int getAlumnos() {
		return alumnos;
	}
	std::string getSport() {
		return sport;
	}
	void print(std::ostream& out = std::cout) const {
		out << sport << ' ' << alumnos;
	}
};

inline std::ostream& operator<<(std::ostream& out, Sport const s) {
	s.print(out);
	return out;
}