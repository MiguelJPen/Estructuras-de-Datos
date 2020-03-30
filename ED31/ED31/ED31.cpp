#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos un texto y devolvemos las palabras que aparecen y en qué línea, 
sin tener en cuenta mayúsuclas y minúsculas y las repeticiones en la misma línea.
*/

std::string toLower(std::string & s) {
	for (char & c : s)
		c = tolower(c);
	return s;
}

bool resuelveCaso() {
	int lines;
	std::cin >> lines;
	if (lines == 0) return false;

	std::map<std::string, std::vector<int>> text;

	std::cin.get();
	for (int i = 1; i <= lines; ++i) { // O(n) siendo n el número de letras (por la conversión a minúsculas)
		std::string s, word;
		std::getline(std::cin, s);
		std::stringstream ss(s);

		while (ss >> word) {
			if (word.length() > 2)
				text[toLower(word)].push_back(i);
		}
	}

	auto it = text.begin();
	while (it != text.end()) { // O(k) siendo k el número de palabras
		int last = 0;
		std::cout << it->first << ' ';
		for (int & num : it->second) {
			if (last != num) {
				std::cout << num << ' ';
				last = num;
			}
		}
		std::cout << '\n';
		++it;
	}
	std::cout << "---\n";

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}