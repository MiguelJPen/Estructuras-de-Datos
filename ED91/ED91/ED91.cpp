#include <iostream>
#include <string>
#include <map>
#include <set>

/*
Miguel Jes�s Pe�alver Carvajal

En este problema recibimos una lista de pel�culas con sus respectivos actores y el tiempo que aparecen
en escena. Despu�s recibimos una lista de pel�culas que se emiten y devolvemos el n�mero de veces que 
m�s se ha emitido una pel�cula, el nombre de la misma y el m�ximo n�mero de minutos que ha aparecido un
actor en escena, junto al nombre de los actores que han aparecido ese tiempo.
*/

typedef struct {
	std::string name;
	int min;
}tActor;

bool operator<(tActor const& a, tActor const& b) {
	return (a.name < b.name);
}

bool resuelveCaso() {
	long long int nFilms, nActors;
	std::string f;
	tActor a;
	std::cin >> nFilms;
	if (nFilms == 0) return false;

	std::map<std::string, std::set<tActor>> films;
	while (nFilms--) { // O(n�log(n)�m�log(m)) siendo n el n�mero de pel�culas y m el n�mero de actores
		std::cin >> f >> nActors;
		films[f];
		
		while (nActors--) {
			std::cin >> a.name >> a.min;
			films[f].insert(a);
		}
	}
	
	std::cin >> nFilms;

	std::map<std::string, long long int> emittedFilms, stagingActors;
	std::set<std::string> maxActors;
	std::string maxFilms;
	long long int maxFilm = 0, maxActor = 0;

	while (nFilms--) { // O(k�m�log(m)) siendo k el n�mero de pel�culas emitidas y m el n�mero de actores.
		std::cin >> f;
		++emittedFilms[f];
		if (emittedFilms[f] >= maxFilm) {
			maxFilms = f;
			maxFilm = emittedFilms[f];
		}

		for (auto const& x : films[f]) {
			stagingActors[x.name] += x.min;

			if (stagingActors[x.name] == maxActor)
				maxActors.insert(x.name);
			else if (stagingActors[x.name] > maxActor) {
				maxActor = stagingActors[x.name];
				maxActors.clear();
				maxActors.insert(x.name);
			}
		}
	}

	std::cout << maxFilm << ' ' << maxFilms << '\n' << maxActor << ' ';
	for (auto const& x : maxActors)
		std::cout << x << ' ';
	std::cout << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}