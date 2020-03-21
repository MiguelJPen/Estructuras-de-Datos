#pragma once

#include <iostream>

#include "deque_eda.h"

/*
Miguel Peñalver Carvajal
*/

template <class T>
class Engordar : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	void engordar(Engordar &l2) {
		while (!l2.empty()) {
			// Introducimos el elemento al inicio de l1.
			Nodo* next = l2.fantasma->sig;
			// Desenganchamos el primer nodo de l2.
			l2.fantasma->sig = next->sig;
			l2.fantasma->sig->ant = l2.fantasma;

			// Lo volvemos a enganchar al inicio de l1.
			Nodo* aux = this->fantasma->sig;
			this->fantasma->sig = next;
			aux->ant = next;
			next->sig = aux;
			next->ant = this->fantasma;

			--l2.nelems;
			++this->nelems;

			// Insertamos el elmento al final de l1.
			if (!l2.empty()) {
				// Desenganchamos el primer elemento de l2.
				next = l2.fantasma->sig;
				l2.fantasma->sig = next->sig;
				l2.fantasma->sig->ant = l2.fantasma;

				// Lo volvemos a enganchar al final de l1.
				aux = this->fantasma->ant;
				this->fantasma->ant = next;
				aux->sig = next;
				next->ant = aux;
				next->sig = this->fantasma;

				--l2.nelems;
				++this->nelems;
			}
		}
	}
	// Imprime la lista por pantalla.
	void print(std::ostream& output = std::cout) const {
		Nodo* aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			output << aux->elem << " ";
			aux = aux->sig;
		}
		output << '\n';
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream& out, Engordar<T> const l) {
	l.print(out);
	return out;
}