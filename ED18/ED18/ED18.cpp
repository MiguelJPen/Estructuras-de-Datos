#include <iostream>
#include <algorithm>

/*
Miguel Jesús Peñalver Carvajal
*/

int numPrec(int const nJefes, int numPrecarios, int prof) {
	int n;
	std::cin >> n;
	if (n == 0 && prof >= nJefes) {
		return ++numPrecarios;
	}
	for (int i = 0; i < n; ++i)
		numPrecarios = std::max(numPrecarios, numPrec(nJefes, numPrecarios, prof + 1));
	return numPrecarios;
}

bool resuelveCaso() {
	int nJefes;
	std::cin >> nJefes;
	if (std::cin.fail()) return false;

	std::cout << numPrec(nJefes, 0, 0) << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}