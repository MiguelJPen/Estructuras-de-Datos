#pragma once

#include <iostream>
#include <string>
#include <set>

#include "deque_eda.h"
#include "stack_eda.h"

/*
Miguel Peñalver Carvajal
*/

template <class T>
class Reorder : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	Reorder reorder1(std::string s) {
		Reorder ret;

		for (long unsigned int i = 0; i < s.size(); i += 2)
			ret.push_back(s.at(i));
		for (long int i = s.size() - 1 - (s.size() % 2); i > 0; i -= 2)
			ret.push_back(s.at(i));

		return ret;
	}

	void reorder2() {
		std::set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
		stack<char> consonants;
		Reorder<char> ret;
		int n = this->nelems;
		char c;

		for (int i = 0; i < n; ++i) {
			c = this->front();
			this->pop_front();

			if (vowels.count(c)) {
				while (!consonants.empty()) {
					ret.push_back(consonants.top());
					consonants.pop();
				}
				ret.push_back(c);
			}
			else consonants.push(c);
		}
		while (!consonants.empty()) {
			ret.push_back(consonants.top());
			consonants.pop();
		}

		this->copia(ret);
	}

	// Imprime la lista por pantalla.
	void print(std::ostream& output = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			output << aux->elem;
			aux = aux->sig;
		}
		output << '\n';
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream& out, Reorder<T> const l) {
	l.print(out);
	return out;
}