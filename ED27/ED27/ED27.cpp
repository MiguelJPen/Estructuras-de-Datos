#include <iostream>
#include <string>
#include <sstream>
#include <queue>

#include "bintree_eda.h"

/*
Miguel Jes�s Pe�alver Carvajal

En este problema, dado el recorrido en preorden de un �rbol binario de b�squeda, devolvemos el recorrido
en postorden. Para la implementaci�n he utilizado colas.
El coste de este algoritmo es lineal respecto al n�mero de nodos.
*/

bintree<long int> treeGenerator(std::queue<long int> & preorder) {
	if (preorder.size() == 1)
		return { preorder.front() };

	long int root = preorder.front();
	std::queue<long int> preorderIzq;
	preorder.pop();

	// Dividimos las colas hasta la ra�z en preorden (el primer elemento) para generar los nodos
	// del hijo izquierdo y los del hijo derecho.
	while (preorder.size() && root > preorder.front()) {
		preorderIzq.push(preorder.front());
		preorder.pop();
	}
	bintree<long int> left = {}, right = {};

	if (preorderIzq.size()) left = treeGenerator(preorderIzq);
	if (preorder.size()) right = treeGenerator(preorder);

	return { left, root, right };
}


std::queue<long int> read() {
	std::queue<long int> ret;
	int tmp;
	std::string s;

	std::getline(std::cin, s);
	std::stringstream str(s);

	while (str >> tmp)
		ret.push(tmp);

	return ret;
}

bool resuelveCaso() {
	bintree<long int> t;
	std::queue<long int> preorder;

	preorder = read();
	if (preorder.size() == 0) return false;

	t = treeGenerator(preorder);

	for (auto& i : t.postorder()) std::cout << i << ' ';
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}