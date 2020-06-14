#ifndef Time_h
#define Time_h

#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>

using namespace std;

/*
Miguel Peñalver Carvajal
Luis Ariza López
*/

class Time {
private:
	int HH;
	int MM;
	int SS;

public: 
	Time() {}

	Time(int hh, int mm, int ss) {
		HH = hh;
		MM = mm;
		SS = ss;
	}
	~Time() {}

	// Lectura y escritura
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

#endif