#pragma once

#include <iostream>

#include "queue_eda.h"

/*
Miguel Peñalver Carvajal
*/

template <class T>
class Inserter : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	// Esta función inserta la lista list2 en la lista principal a partir de la posición pos.
	void insert(Inserter &list2, int pos) {
		// Insertar tiene orden constante, sin embargo debemos encontrar el nodo a partir del cual 
		// introducimos la lista, que es lo que podría llevar más tiempo, aunque no la modificamos.
		Nodo *aux = this->prim;
		
		if (pos == 0) {
			this->prim = list2.prim;
			list2.ult->sig = aux;
		}
		else {
			for (int i = 0; i < pos - 1; ++i)
				aux = aux->sig;
			Nodo *aux2 = aux->sig;
			aux->sig = list2.prim;
			list2.ult->sig = aux2;
			if (pos == this->nelems) this->ult = list2.ult;
		}

		this->nelems += list2.nelems;
		list2.nelems = 0;
		list2.prim = nullptr;
		list2.ult = nullptr;
	}
	// Imprime la lista por pantalla.
	void print(std::ostream& output = std::cout) const {
		Nodo* aux = this->prim;
		while (aux != nullptr) {
			output << aux->elem << " ";
			aux = aux->sig;
		}
		output << '\n';
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream& out, Inserter<T> const l) {
	l.print(out);
	return out;
}