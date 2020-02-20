#pragma once

#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>

using namespace std;

/*
Miguel Jesús Peñalver Carvajal
*/

class Time {
private:
	int HH;
	int MM;
	int SS;

	bool correcta(int HH, int MM, int SS) {
		return HH >= 0 && HH < 24 && MM >= 0 && MM < 60 && SS >= 0 && SS < 60;
	}

public: 
	Time() {}

	Time(int hh, int mm, int ss) {
		if (correcta(hh, mm, ss)) {
			HH = hh;
			MM = mm;
			SS = ss;
		}
		else throw domain_error("Datos inválidos.");
	}

	Time(int seconds) {
		int hh = seconds / 3600;
		int mm = (int)((seconds - hh * 3600) / 60);
		int ss = seconds - (hh * 3600 + mm * 60);
		
		if (correcta(hh, mm, ss)) {
			HH = hh;
			MM = mm;
			SS = ss;
		}
		else throw domain_error("Datos inválidos.");
	}
	~Time() {}

	// Observers
	int hora() const { return HH; }
	int minutos() const { return MM; }
	int segundos() const { return SS; }

	// Comparing operators
	bool operator<(Time const& h) const {
		return HH * 3600 + MM * 60 + SS < h.HH * 3600 + h.MM * 60 + h.SS;
	}

	bool operator==(Time const& h) const {
		return HH == h.HH && MM == h.MM && SS == h.SS;
	}

	// Arithmetic operators
	Time operator+(Time const& h) const {
		// Throws an error in the constructor if the sum is more than 24 hours.
		return *(new Time(HH * 3600 + h.HH * 3600 + MM * 60 + h.MM * 60 + SS + h.SS));
	}
	
	// Read and write
	void read(std::istream& input = std::cin) {
		int h, m, s;
		char c;

		input >> h >> c >> m >> c >> s;
		*this = Time(h, m, s);
	}

	void print(std::ostream& out = std::cout) const {
		char c = ':';
		out << setw(2) << setfill('0') << HH << c << setw(2) << setfill('0') << MM << c << setw(2) << setfill('0') << SS;
	}
};

inline ostream& operator<<(ostream& out, Time const h) {
	h.print(out);
	return out;
}

inline istream& operator>>(istream& in, Time& h) {
	h.read(in);
	return in;
}