#include <iostream>

#include "TreeData.h"

void resuelveCaso() {
	TreeData<char> t;
	t = readTree('.');

	std::cout << t.nodes(t) << ' ' << t.leaves(t) << ' ' << t.height(t);
}

int main() {
	int n;
	std::cin >> n;
	while (--n) resuelveCaso();
	return 0;
}