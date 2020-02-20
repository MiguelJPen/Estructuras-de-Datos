#pragma once

#include <iostream>
#include <math.h>

template <typename T>

class Complex {
private:
	T real, imag;

public:
	// Constructor
	Complex() {}
	Complex(T r, T i) {
		real = r;
		imag = i;
	}
	// Destructor
	~Complex() {}

	// Arithmetic operators
	Complex operator+(Complex const& c) const {
		return Complex(real + c.real, imag + c.imag);
	}
	Complex operator*(Complex const& c) const {
		return Complex(real * c.real - imag * c.imag, real * c.imag + c.real * imag);
	}
	float mod() const {
		return sqrt(pow(real, 2) + pow(imag, 2));
	}

	// Read and write
	void read(std::istream& input = std::cin) {
		T r, i;
		
		input >> r >> i;
		*this = Complex(r, i);
	}
	void print(std::ostream& output = std::cout) {
		char mas = '+', i = 'i';
		output << real << mas << imag << i;
	}

	// Vemos si converge en el conjunto de Mandelbrot
	bool mandelbrotConverges(int const& nIter) {
		Complex<T> c = { 0, 0 };

		for (int i = 0; i < nIter; ++i) {
			c = c * c + *this;
			if (c.mod() > 2) return false;
		}
		return true;
	}
};

template <typename T>
inline std::ostream& operator<<(std::ostream& out, Complex<T> const c) {
	c.print(out);
	return out;
}

template <typename T>
inline std::istream& operator>>(std::istream& in, Complex<T> & c) {
	c.read(in);
	return in;
}