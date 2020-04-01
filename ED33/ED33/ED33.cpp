#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <set>

#include "Problems.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos una lista de equipos con los problemas que han resuelto y devolvemos la clasificación
según aquellos resueltos correctamente.
*/

void resuelveCaso() {
	std::map<std::string, Problem> numSolved;
	std::map<std::string, std::map<std::string, int>> notCorrect;
	std::string s, name, problem, points, sol;
	std::getline(std::cin, s);

	while (s != "FIN") {
		std::stringstream ss(s);

		ss >> name >> problem >> points >> sol;
		if (numSolved.count(name) == 0) 
			numSolved[name].setName(name);
		if (sol != "AC")
			++notCorrect[name][problem];
		if (sol == "AC" && numSolved[name].notSolved(problem)) {
			numSolved[name].addProblem(problem, std::stoi(points));
			numSolved[name].addExtraTime(notCorrect[name][problem]);
		}
		std::getline(std::cin, s);
	}

	// Mostrar el ránking es: O(n log(n)), siendo n el número de equipos.
	std::set<Problem> list;
	for (auto it : numSolved)
		list.insert(it.second);
	for (auto it : list)
		std::cout << it << '\n';
	std::cout << "---\n";
}

int main() {
	int n;
	std::cin >> n;
	std::cin.get();
	while (n--) resuelveCaso();
	return 0;
}