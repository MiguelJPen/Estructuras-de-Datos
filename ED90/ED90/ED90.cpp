#include <iostream>
#include <map>
#include <vector>

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos una lista de números y devolvemos los números que aparecen, en el mismo orden
en el que se insertaron, junto al número de veces que aparecen.
*/

bool resuelveCaso() {
	long long int n, temp;
	std::cin >> n;
	if (std::cin.fail()) return false;

	std::map<long long int, long long int> map;
	std::vector<long long int> order;

	while (n--) { //O(log(n))
		std::cin >> temp;
		if (map.count(temp) == 0) order.push_back(temp);
		++map[temp];
	}

	for (auto const& x : order) // O(n log(n))
		std::cout << x << ' ' << map[x] << '\n';
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}