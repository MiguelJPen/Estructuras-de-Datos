#include <iostream>

/*
Miguel Jesús Peñalver Carvajal
*/

void numPrec(int const nJefes, int &numPrecarios, int prof) {
	int max, n;
	std::cin >> n;
	if (n == 0 && prof >= nJefes) {
		++numPrecarios;
		return;
	}
	for (int i = 0; i < n; ++i)
		numPrec(nJefes, numPrecarios, prof + 1);
}

bool resuelveCaso() {
	int nJefes, numPrecarios = 0;
	std::cin >> nJefes;
	if (std::cin.fail()) return false;

	numPrec(nJefes, numPrecarios, 0);
	std::cout << numPrecarios << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}