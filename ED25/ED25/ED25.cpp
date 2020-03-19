#include <iostream>
#include <string>
#include <vector>
#include <math.h>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema buscamos el múltiplo de 7 que aparezca en un nodo accesible lo más
cercano a la raíz.
El coste de este algoritmo es linel respecto al número de nodos del árbol, ya que el
coste de inicializar el vector de booleanos de primos es constante.
*/

typedef struct {
	long int number, height;
}tMultiplo;

tMultiplo multiplo(bintree<int> r, std::vector<bool> const& primos) {
	if (r.empty() || !primos[r.root()]) return { 0 , -1 };
	tMultiplo left = multiplo(r.left(), primos), right = multiplo(r.right(), primos), ret = { 0, -2 };
	if (r.root() % 7 == 0)
		ret = { r.root(), 0 };
	// En caso de que en ambas ramas haya múltiplos de 7, cogemos el menos profundo.
	else if (left.height != -1 && right.height != -1)
		if (right.height < left.height)
			return { right.number, ++right.height };
		else
			return { left.number, ++left.height };
	
	else if (left.height != -1)
		return { left.number, ++left.height };
	else if (right.height != -1)
		return { right.number, ++right.height };
	return { ret.number, ++ret.height };
}

void resuelveCaso(std::vector<bool> const& primos) {
	bintree<int> t = leerArbol(-1);

	tMultiplo mult = multiplo(t, primos);

	if (mult.height == -1) std::cout << "NO HAY" << '\n';
	else std::cout << mult.number << ' ' << mult.height << '\n';
}

void construirPrimos(std::vector<bool>& primos) {
	primos[0] = false;
	primos[1] = false;
	for (unsigned int i = 2; i < primos.size(); ++i) primos[i] = false;
	for (unsigned int i = 2; i < primos.size(); ++i)
		for (unsigned int j = 2; i*j < primos.size(); ++j)
			primos[i*j] = true;
}

int main() {
	int n;
	std::cin >> n;
	std::vector<bool> primos;
	primos.resize(5000);
	construirPrimos(primos);
	while (n--) resuelveCaso(primos);
	return 0;
}