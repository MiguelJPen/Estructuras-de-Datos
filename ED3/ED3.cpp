#include <iostream>

#include "Complex.h"

/*
Miguel Jesús Peñalver Carvajal

Con este programa comprobamos si un número pertenece al conjunto de Mandelbrot.
Recibimos un número complejo, el cual iteramos el número de veces que se nos indica
como máximo, y escribimos "SI" si dicho número pertenece al conjunto y "NO" en 
caso contrario. Implementamos una clase "Complex" que trabaja con los números
complejos y en ella quedan definidas las operaciones correspondientes.
*/

void resuelveCaso() {
	Complex<float> c;
	int nIter;

	std::cin >> c >> nIter;

	std::cout << (c.mandelbrotConverges(nIter) ? "SI" : "NO") << "\n";
}

int main() {
	int nCasos;
	std::cin >> nCasos;
	for (int i = 0; i < nCasos; ++i)
		resuelveCaso();
	return 0;
}