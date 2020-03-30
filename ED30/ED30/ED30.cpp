#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <set>

/*
Miguel Jesús Peñalver Carvajal

En este problema recibimos dos diccionarios y devolvemos los elementos añadidos, borrados y cambiados
al comparar ambos. Usamos iteradores para conseguir O(n).
*/

std::map<std::string, int> readDic() { // O(n log(k))
	std::map<std::string, int> map;
	std::string clave, s;
	int valor;
	std::getline(std::cin, s);
	std::stringstream ss(s);

	while (ss >> clave >> valor)
		map[clave] = valor;

	return map;
}

std::string printSet(std::set<std::string> const& set) { // O(k) K = número de elementos de set
	std::string s = "";
	for (auto it = set.begin(); it != set.end(); ++it) s += *it + ' ';
	s += '\n';

	return s;
}

void resuelveCaso() {
	std::map<std::string, int> first, second;
	first = readDic();
	second = readDic();

	// Usamos set para imprimir los cambios en orden.
	std::set<std::string> _new, erased, changed;

	// Usando los iteradores conseguimos que esta función sea O(n)
	auto itFirst = first.begin(), itSecond = second.begin();

	while (itFirst != first.end() && itSecond != second.end()) {
		if (itFirst->first.compare(itSecond->first) < 0) {
			erased.insert(itFirst->first);
			++itFirst;
		}
		else if (itFirst->first.compare(itSecond->first) > 0) {
			_new.insert(itSecond->first);
			++itSecond;
		}
		else { // La misma clave
			if (itFirst->second != itSecond->second) changed.insert(itFirst->first);
			++itFirst;
			++itSecond;
		}
	}
	while (itFirst != first.end()) {
		erased.insert(itFirst->first);
		++itFirst;
	}
	while (itSecond != second.end()) {
		_new.insert(itSecond->first);
		++itSecond;
	}

	if (_new.size() == 0 && erased.size() == 0 && changed.size() == 0) {
		std::cout << "Sin cambios\n---\n";
		return;
	}
	if (_new.size() != 0) std::cout << "+ " << printSet(_new);
	if (erased.size() != 0) std::cout << "- " << printSet(erased);
	if (changed.size() != 0) std::cout << "* " << printSet(changed);
	std::cout << "---\n";
}

int main() {
	int n;
	std::cin >> n;
	std::cin.get();
	while (n--) resuelveCaso();
	return 0;
}