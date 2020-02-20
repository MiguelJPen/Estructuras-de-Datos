#include <iostream>
#include <string>

#include "stack_eda.h"

/*
Miguel Peñalver Carvajal

En este ejercicio, dada una cadena de caracteres, devolvemos si todos los paréntesis, corchetes y llaves están correctamente cerradas.

El coste de este algoritmo es lineal respecto al número de caracteres de la cadena a analizar.
*/

const char open[] = { '(', '[', '{' };
const char close[] = { ')', ']', '}' };

bool isOpen(char const& c) {
	for (int i = 0; i < 3; ++i)
		if (open[i] == c) return true;
	return false;
}

bool isClose(char const& c) {
	for (int i = 0; i < 3; ++i)
		if (close[i] == c) return true;
	return false;
}

char mirror(char const& c) {
	for (int i = 0; i < 3; ++i)
		// Given a bracket, it returns the mirror.
		if (c == open[i]) return close[i];
	return ' ';
}

bool resuelveCaso() {
	std::string cad;

	// We read a whole line.
	std::getline(std::cin, cad);
	if (std::cin.fail()) return false;

	stack<char> car;
	bool equilibrated = true;

	for (unsigned int i = 0; i < cad.size(); ++i) {
		if (isOpen(cad[i]))
			// If the element is an opening bracket, we add it to the stack.
			car.push(cad[i]);

		else if (isClose(cad[i])) {
			// In case there are no elements in the stack or they are different from the one we are looking at.
			if (car.empty() || mirror(car.top()) != cad[i]) equilibrated = false;
			// If it is equal, we retire it from the stack.
			else car.pop();
		}
	}
	// In case wwe haven´t closed all the brackets.
	if (!car.empty()) equilibrated = false;

	if (equilibrated) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}