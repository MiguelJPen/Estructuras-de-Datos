#include <iostream>
#include <list>
#include <algorithm>
#include <vector>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos un árbol binario y devolvemos su perfil izquierdo.
v1 - El coste de este algoritmo es O(n).
v2 - El coste de este algoritmo es O(n).
*/

typedef struct {
	int height;
	std::list<int> v;
}tSide;

std::vector<std::pair<int, int>> leftSidev2(bintree<int> t) {
	std::vector<std::pair<int, int>> lefts;
	int height = 0;

	if (!t.empty()) {
		std::queue<std::pair<bintree<int>, int>> pendientes;
		pendientes.push(std::make_pair(t, height));
		lefts.push_back(std::make_pair(t.root(), height));

		while (!pendientes.empty()) {
			std::pair<bintree<int>, int> sig = pendientes.front();
			pendientes.pop();
			if (lefts.back().second < sig.second)
				lefts.push_back(std::make_pair(sig.first.root(), sig.second));

			++sig.second;
			if (!sig.first.left().empty())
				pendientes.push(std::make_pair(sig.first.left(), sig.second));
			if (!sig.first.right().empty())
				pendientes.push(std::make_pair(sig.first.right(), sig.second));
		}
	}
	return lefts;
}

tSide leftSidev1(bintree<int> t) {
	if (t.empty()) return { 0, {} };
	
	tSide left = leftSidev1(t.left()), right = leftSidev1(t.right());

	if (right.height >= left.height)
		right.v.resize(right.height - left.height);
	else right.v.clear();

	right.v.splice(right.v.end(), left.v);

	right.v.push_back(t.root());

	right.height = std::max(left.height, right.height) + 1;

	return right;
}

void resuelveCaso() {
	bintree<int> t;
	t = leerArbol(-1);

	/*std::list<int> l(leftSidev1(t).v);
	l.reverse();*/
	std::vector<std::pair<int, int>> l = leftSidev2(t);
	
	/*for (auto const& x : l)
		std::cout << x << ' ';*/
	for (auto const& x : l)
		std::cout << x.first << ' ';

	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}