#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Film.h"

using namespace std;

/*
Miguel Jes�s Pe�alver Carvajal

En este problema, se reciben la hora de inicio, la duraci�n y el nombre de una serie de pel�culas, las cuales
se guardan en un vector y se ordenan seg�n la hora de finalizaci�n de las mismas. En caso de que la hora sea
la misma, estas aparecen ordenadas por orden alfab�tico. La clase pel�cula se encarga de controlar la aritm�tica
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