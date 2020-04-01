#include <iostream>
#include <list>
#include <algorithm>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos un árbol binario y devolvemos su perfil izquierdo.
El coste de este algoritmo es O(n log(n)) por el método reverse().
*/

typedef struct {
	int height;
	std::list<int> v;
}tSide;

tSide leftSide(bintree<int> t) {
	if (t.empty()) return { 0, {} };
	
	tSide left = leftSide(t.left()), right = leftSide(t.right());

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

	std::list<int> l(leftSide(t).v);
	l.reverse();
	
	for (auto const& x : l)
		std::cout << x << ' ';
	std::cout << '\n';
}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}