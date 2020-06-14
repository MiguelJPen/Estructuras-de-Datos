#pragma once

#include <iostream>
#include <iomanip>

/*
Miguel Peñalver Carvajal
*/

class Date {
private:
	int dd, hh, mm;

public:
	Date() {}
	Date(int dd, int hh, int mm) {
		this->dd = dd;
		this->hh = hh;
		this->mm = mm;
	}
	~Date() {}

	bool operator<(Date const& d) const {
		return dd < d.dd || dd == d.dd && hh < d.hh || dd == d.dd && hh == d.hh && mm < d.mm;
	}
	bool operator==(Date const& d) const {
		return dd == d.dd && hh == d.hh && mm == d.mm;
	}
	int day() const {
		return dd;
	}

	// Reading and printing.
	void read(std::istream& input = std::cin) {
		int d, h, s;
		char c;

		input >> d >> h >> c >> s;
		*this = Date(d, h, s);
	}
	void print(std::ostream& out = std::cout) const {
		char c = ':';
		out << std::setw(2) << std::setfill('0') << hh << c << std::setw(2) << std::setfill('0') << mm;
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