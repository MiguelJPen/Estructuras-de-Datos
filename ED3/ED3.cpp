#include <iostream>

#include "Complex.h"

/*
Miguel Jes�s Pe�alver Carvajal

Con este programa comprobamos si un n�mero pertenece al conjunto de Mandelbrot.
Recibimos un n�mero complejo, el cual iteramos el n�mero de veces que se nos indica
como m�ximo, y escribimos "SI" si dicho n�mero pertenece al conjunto y "NO" en 
caso contrario. Implementamos una clase "Complex" que trabaja con los n�meros
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