#include <iostream>

#include "DuplicateList.h"

/*
Miguel Pe�alver Carvajal

Este problema lo resolvemos con una clase que hereda de deque y a�adimos una funci�n
que duplica la lista y otra que la imiprime.
*/

bool resuelveCaso() {
	try {
		DuplicateList<int> list;

		list.duplicate();
		list.print();
	}
	catch (std::domain_error &e) {
		return false;
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}