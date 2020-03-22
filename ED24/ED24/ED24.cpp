#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "bintree_eda.h"

bintree<long int> treeGenerator(std::vector<long int> const& preorder, std::vector<long int> const& inorder) {
	
}

std::vector<long int> read() {
	std::vector<long int> ret;
	int tmp;
	std::string s;

	std::getline(std::cin, s);
	std::stringstream str(s);
	
	while (str >> tmp)
		ret.push_back(tmp);
	
	return ret;
}

bool resuelveCaso() {
	bintree<long int> t;
	std::vector<long int> preorder, inorder;

	preorder = read();
	inorder = read();

	t = generateTree(preorder, inerder);

	for (auto& i : t.postorder()) std::cout << i << ' ';
	std::cout << '\n';
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}