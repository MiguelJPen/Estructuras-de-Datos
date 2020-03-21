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
	// Función que intercambia nodos dos a dos.
	void mix() {
		Nodo *cur = this->prim, *next = this->prim->sig, *aux;

		if (next != nullptr) this->prim = next;

		while (cur != nullptr && next != nullptr) {
			aux = next->sig;

			if (aux != nullptr && aux->sig != nullptr)
				cur->sig = aux->sig;
			else cur->sig = aux;

			next->sig = cur;
			cur = aux;

			if (cur != nullptr) next = cur->sig;
		}
		this->ult = cur;
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