#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Film.h"

using namespace std;

/*
Miguel Jesús Peñalver Carvajal

En este problema, se reciben la hora de inicio, la duración y el nombre de una serie de películas, las cuales
se guardan en un vector y se ordenan según la hora de finalización de las mismas. En caso de que la hora sea
la misma, estas aparecen ordenadas por orden alfabético. La clase película se encarga de controlar la aritmética
del vector de peliculas y de los datos de las mismas.
*/

bool resuelveCaso() {
	int nFilms;

	cin >> nFilms;
	if (nFilms == 0) return false;

	vector<Film> films(nFilms);
	for (Film& f : films)
		cin >> f;

	sort(films.begin(), films.end());
	
	for (Film&f : films)
		cout << f << "\n";
	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}