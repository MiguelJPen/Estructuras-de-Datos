#pragma once

#include <iostream>

#include "queue_eda.h"

/*
Miguel Peñalver Carvajal
*/

template <class T>
class Mixer : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void mix(Mixer &l2) {
		// La función mix tiene un coste lineal respecto a la suma de elementos de ambas listas.
		Nodo *aux = this->prim;
		Nodo *aux2 = l2.prim;
		Nodo nodo, *current = &nodo; // Creamos un nodo que va a ser el inicial y un puntero a dicho nodo.

		// Creamos un nuevo nodo, el  cual nos servirá para enganchar la nueva lista ordenada, para 
		// ello comparamos los primeros números de ambas listas y cogemos el menor.
		while (aux != nullptr && aux2 != nullptr) {
			if (aux->elem < aux2->elem) {
				current->sig = aux;
				aux = aux->sig;
			}
			else {
				current->sig = aux2;
				aux2 = aux2->sig;
			}
			current = current->sig;
		}
		// Al acabar alguna de las dos listas, unimos el final que nos falta.
		if (aux == nullptr) {
			current->sig = aux2;
			this->ult = l2.ult;
		}
		else current->sig = aux;

		this->nelems += l2.nelems;
		this->prim = nodo.sig;
		l2.prim = nullptr;
		l2.ult = nullptr;
		l2.nelems = 0;
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
inline std::ostream& operator<<(std::ostream& out, Mixer<T> const l) {
	l.print(out);
	return out;
}