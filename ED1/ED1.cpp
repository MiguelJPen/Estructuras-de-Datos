#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include"Time.h"

/*
Miguel Pe�alver Carvajal BLA BLA BLA

Comprobamos la menor hora registrada para que pase el siguiente tren. En caso de que dicha hora consultada sea demasiado tarde,
es decir, no haya trenes m�s tarde ese d�a, se escribir� "NO". Si la hora que tratamos de consultar es incorrecta, se escribir�
"ERROR".
*/

using namespace std;

bool resuelveCaso() {
	int nTrenes, nConsultas;

	cin >> nTrenes >> nConsultas;
	if (nTrenes == 0 && nConsultas == 0)
		return false;

	vector<Time> trenes(nTrenes);

	// Leemos los horarios de los trenes que parten de la estaci�n.
	for (Time& h : trenes)
		cin >> h;

	for (int i = 0; i < nConsultas; ++i) {
		Time h;
		try {
			cin >> h;
			auto pos = lower_bound(trenes.begin(), trenes.end(), h);
			if (pos == trenes.end())
				cout << "NO\n";
			else cout << trenes[(pos - trenes.begin())] << "\n";
		}
		catch (domain_error & e) {
			cout << "ERROR\n";
		}
	}
	cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}