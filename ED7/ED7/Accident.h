#pragma once

#include <iostream>

#include "Date.h"

/*
Miguel Peñalver Carvajal
*/

class Accident {
private:
	int victims;
	Date date;
public:
	Accident() {}
	Accident(Date date, int victims) {
		this->victims = victims;
		this->date = date;
	}
	~Accident() {}

	// Comparing operators
	bool operator>=(Accident const& a) const {
		return victims >= a.victims;
	}

	// Reading function
	void read(std::istream& input = std::cin) {
		int vic;
		Date d;

		input >> d >> vic;
		*this = Accident(d, vic);
	}

	// Prints only the date of the accident
	void printDate() const {
		std::cout << date << '\n';
	}
};

inline std::istream& operator>>(std::istream& in, Accident& a) {
	a.read(in);
	return in;
}