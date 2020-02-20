#pragma once

#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>

#include "Time.h"

using namespace std;

/*
Miguel Jesús Peñalver Carvajal
*/

class Film {
private:
	Time ini;
	Time fin;
	string name;

public:
	Film() {}

	Film(Time i, Time f, string n) {
		ini = i;
		fin = f;
		name = n;
	}

	~Film() {}

	// Observers
	Time inicio() const { return ini; }
	Time final() const { return fin; }
	string nombre() const { return name; }

	// Comparing operators
	bool operator<(Film const& f) const {
		return fin < f.fin || (fin == f.fin && name < f.name);
	}

	// Read and write
	void read(istream& input = cin) {
		Time ini, dur;
		string name;

		input >> ini >> dur;
		getline(input, name, '\n');
		*this = Film(ini, ini + dur, name);
	}

	void print(ostream& out = cout) {
		out << fin << " " << name;
	}
};

inline istream& operator>>(istream& in, Film& f) {
	f.read(in);
	return in;
}

inline ostream& operator<<(ostream& out, Film& f) {
	f.print(out);
	return out;
}