#pragma once

#include <iostream>
#include <iomanip>

/*
Miguel Peñalver Carvajal
*/

class Date {
private:
	int dd, mm, yy;

public:
	Date() {}
	Date(int dd, int mm, int yy) {
		this->dd = dd;
		this->mm = mm;
		this->yy = yy;
	}
	~Date() {}

	// Reading and printing.
	void read(std::istream& input = std::cin) {
		int d, m, y;
		char c;

		input >> d >> c >> m >> c >> y;
		*this = Date(d, m, y);
	}
	void print(std::ostream& out = std::cout) const {
		char c = '/';
		out << std::setw(2) << std::setfill('0') << dd << c << std::setw(2) << std::setfill('0') << mm << c << std::setw(4) << std::setfill('0') << yy;
	}
};

inline std::ostream& operator<<(std::ostream& out, Date const d) {
	d.print(out);
	return out;
}

inline std::istream& operator>>(std::istream& in, Date& d) {
	d.read(in);
	return in;
}