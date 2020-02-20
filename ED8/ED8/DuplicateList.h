#pragma once

#include <iostream>

#include "deque_eda.h"

/*
Miguel Peñalver Carvajal
*/

template <class T>
class DuplicateList : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	DuplicateList () {
		deque<T>();
		int elem;

		std::cin >> elem;
		if (std::cin.fail()) throw std::domain_error("Invalid data.");
		while (elem != 0) {
			this->push_back(elem);
			std::cin >> elem;
		}
	}

	~DuplicateList() {
	}

	// Duplicating function
	void duplicate() {
		// Este algoritmo tiene complejidad n (siendo n el número de elementos de la lista),
		// ya que añadir un elemento tiene orden constante.
		Nodo *tmp = this->fantasma->ant;
		while (tmp != this->fantasma) {
			this->inserta_elem(tmp->elem, tmp, tmp->sig);
			tmp = tmp->ant;
		}
	}

	// Printing
	void print() { 
		Nodo *nodo = this->fantasma->sig;
		for (int i = 0; i < this->nelems; ++i) {
			std::cout << nodo->elem << ' ';
			nodo = nodo->sig;
		}
		std::cout << '\n';
	}
};