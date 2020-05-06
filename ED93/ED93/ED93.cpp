#include <iostream>
#include <map>
#include <vector>
#include <string>

/*
Miguel Jes�s Pe�alver Carvajal

En este problema recibimos una serie de comandos en BASIC, los cuales devolvemos reordenados,
con saltos de l�nea de diez unidades entre instrucci�n e instrucci�n.
*/

void resuelveCaso() {
	// En este mapa nos quedamos con la salida.
	std::map<int, std::pair<std::string, long long int>> out;
	// En este mapa guardamos los n�meros de l�nea que han cambiado.
	std::map<long long int, long long int> numberChange;
	
	long long int line = 1, nextLine = 0, i = 10;
	std::string aux;

	// Leemos la informaci�n. O(n�log(n)), siendo n el n�mero de elementos.
	std::cin >> line;
	while (line != 0) {
		std::cin >> aux;
		if (aux != "RETURN")
			std::cin >> nextLine;
		out[i] = std::make_pair(aux, nextLine);
		numberChange[line] = i;
		i += 10;
		std::cin >> line;
	}

	// Cambiamos los saltos de l�nea. O(n�log(n)), siendo n el n�mero de elementos.
	for (auto & it : out) {
		if (it.second.first != "RETURN")
			it.second.second = numberChange[it.second.second];
	}

	// Mostramos el resultado por pantalla. O(n), siendo n el n�mero de elementos.
	for (auto const& it : out) {
		if (it.second.first != "RETURN")
			std::cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
		else 	
			std::cout << it.first << ' ' << it.second.first << '\n';
	}
	std::cout << "---\n";
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}