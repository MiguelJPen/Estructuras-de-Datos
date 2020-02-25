#include <iostream>

#include "queue_eda.h"

/*
Miguel Peñalver Carvajal

En este problema nos dan el número de alumnos de una clase y el salto a la hora de elegir uno que se
va de la lista, de la lista que devolvemos el alumno que sale a la pizarra.
*/

int getStudent(int nStudent, int nJump) {
	queue<int> alumnos;
	int i = 1;
	
	for (int i = 1; i <= nStudent; ++i) alumnos.push(i);

	while (alumnos.size() != 1) {
		// Metemos en la parte final del array un elemento de la parte frontal.
		// Solo se ejecuta si no queremos eliminarlo de la lista.
		if (i % (nJump + 1) != 0) alumnos.push(alumnos.front());
		// Eliminamos el primer elemento.
		alumnos.pop();
		++i;
	}

	return alumnos.front();
}

bool resuelveCaso() {
	int nStudent, nJump;

	std::cin >> nStudent >> nJump;
	if (nStudent == 0 && nJump == 0) return false;

	std::cout << getStudent(nStudent, nJump) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}