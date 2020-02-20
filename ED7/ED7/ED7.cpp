#include <iostream>

#include "Accident.h"
#include "stack_eda.h"

/*
Miguel Peñalver Carvajal

En este problema recibimos una lista de accidentes de avión con la fecha y el número de víctimas y, para
cada uno, devolveremos el accidente anterior con un numero de víctimas superior.
*/

bool resuelveCaso() {
	stack<Accident> stack;
	long long int nDates;
	Accident aux;
	
	std::cin >> nDates;
	if (std::cin.fail()) return false;

	// Este algoritmo, en el caso peor, en el que la lista esté ordenada de menor a mayor, tiene complejidad n.
	// Ya que meteríamos y sacaríamos el elemento en la siguiente iteración.
	for (long long int i = 0; i < nDates; ++i) {
		std::cin >> aux;
		// Vamos vaciando la pila, hasta encontrar alguno con más víctimas que el leído.
		while (!stack.empty() && aux >= stack.top())
			stack.pop();

		if (stack.empty())
			std::cout << "NO HAY" << '\n';
		else 
			stack.top().printDate();

		// Metemos el leído en la pila para compararlo con los siguiente.
		stack.push(aux);
	}
	std::cout << "---\n";
	
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}