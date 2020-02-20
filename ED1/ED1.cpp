#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include"Time.h"

/*
Miguel Peñalver Carvajal BLA BLA BLA

Comprobamos la menor hora registrada para que pase el siguiente tren. En caso de que dicha hora consultada sea demasiado tarde,
es decir, no haya trenes más tarde ese día, se escribirá "NO". Si la hora que tratamos de consultar es incorrecta, se escribirá
"ERROR".
*/

using namespace std;

bool resuelveCaso() {
	int nTrenes, nConsultas;

	cin >> nTrenes >> nConsultas;
	if (nTrenes == 0 && nConsultas == 0)
		return false;

	vector<Time> trenes(nTrenes);

	// Leemos los horarios de los trenes que parten de la estación.
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