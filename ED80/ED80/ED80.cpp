#include <iostream>

#include "bintree_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema creamos una funci�n externa con la que vemos si un �rbol geneal�gico binario
es correcto seg�n las pautas del enunciado.
El coste de este algoritmo es lineal respecto al n�mero de nodos del �rbol.
*/

typedef struct {
	int height, age;
	bool ok;
} tSon;

tSon isGenealogic(bintree<int> const& t) {
	if (t.empty()) return { 0, -1, true };

	bool ok = true;
	tSon left = isGenealogic(t.left()), right = isGenealogic(t.right());
	if (left.age != -1)
		ok &= (left.age < t.root() - 17);
	if (right.age != -1)
		ok &= (right.age < t.root() - 17, right.age < left.age - 1);


	return { std::max(left.height, right.height) + 1, t.root(), ok && left.ok && right.ok && !(left.age == -1 && right.age != -1)};
}

void resuelveCaso() {
	bintree<int> t;
	t = leerArbol(-1);

	tSon ret = isGenealogic(t);
	if (ret.ok)
		std::cout << "SI" << ' ' << ret.height << '\n';
	else
		std::cout << "NO" << '\n';

}

int main() {
	int n;
	std::cin >> n;
	while (n--) resuelveCaso();
	return 0;
}