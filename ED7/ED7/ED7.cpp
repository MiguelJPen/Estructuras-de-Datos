#include <iostream>

#include "Accident.h"
#include "stack_eda.h"

/*
Miguel Pe�alver Carvajal

En este problema recibimos una lista de accidentes de avi�n con la fecha y el n�mero de v�ctimas y, para
cada uno, devolveremos el accidente anterior con un numero de v�ctimas superior.
*/

bool resuelveCaso() {
	stack<Accident> stack;
	long long int nDates;
	Accident aux;
	
	std::cin >> nDates;
	if (std::cin.fail()) return false;

	// Este algoritmo, en el caso peor, en el que la lista est� ordenada de menor a mayor, tiene complejidad n.
	// Ya que meter�amos y sacar�amos el elemento en la siguiente iteraci�n.
	for (long long int i = 0; i < nDates; ++i) {
		std::cin >> aux;
		// Vamos vaciando la pila, hasta encontrar alguno con m�s v�ctimas que el le�do.
		while (!stack.empty() && aux >= stack.top())
			stack.pop();

		if (stack.empty())
			std::cout << "NO HAY" << '\n';
		else 
			stack.top().printDate();

		// Metemos el le�do en la pila para compararlo con los siguiente.
		stack.push(aux);
	}
	std::cout << "---\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}