#include <iostream>
#include <string>
#include <sstream>
#include <queue>

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema, dado el recorrido en preorden y en inorden de un árbol binario, devolvemos el recorrido 
en postorden. Para la implementación he utilizado colas.
El coste de este algoritmo es cuadrático en el caso peor respecto al número de nodos.
*/

bintree<long int> treeGenerator(std::queue<long int> & preorder, std::queue<long int> & inorder) {
	if (preorder.size() == 1)
		return { preorder.front() };
	
	long int first = preorder.front();
	std::queue<long int> preorderIzq, inorderIzq;
	preorder.pop();

	// Dividimos las colas hasta la raíz en preorden (el primer elemento) para generar los nodos
	// del hijo izquierdo y los del hijo derecho.
	while (inorder.front() != first) {
		preorderIzq.push(preorder.front());
		inorderIzq.push(inorder.front());
		preorder.pop();
		inorder.pop();
	}
	inorder.pop();
	bintree<long int> left = {}, right = {};
	
	if (preorderIzq.size()) left = treeGenerator(preorderIzq, inorderIzq);
	if (preorder.size()) right = treeGenerator(preorder, inorder);
	
	return { left, first, right };
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
	std::queue<long int> preorder, inorder;

	preorder = read();
	if (preorder.size() == 0) return false;
	inorder = read();

	t = treeGenerator(preorder, inorder);

	for (auto& i : t.postorder()) std::cout << i << ' ';
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}