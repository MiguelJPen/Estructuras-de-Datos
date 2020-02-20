#pragma once

#include <iostream>

using namespace std;

class Monomy {
private:
	int exp, coef;
public:
	Monomy() {}
	Monomy(int coef, int exp) {
		this->coef = coef;
		this->exp = exp;
	}
	~Monomy() {}

	bool isValid() {
		return coef != 0 || exp != 0;
	}
	int getCoef() {
		return coef;
	}
	int getExp() {
		return exp;
	}
	void addCoef(int n) {
		coef += n;
	}

	// Reading.
	void read(std::istream& input = std::cin) {
		int exp, coef;

		input >> coef >> exp;
		*this = Monomy(coef, exp);
	}
};

inline istream& operator>>(istream& in, Monomy& m) {
	m.read(in);
	return in;
}