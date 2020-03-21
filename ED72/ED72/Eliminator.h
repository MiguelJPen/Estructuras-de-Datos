#pragma once

#include <iostream>

#include "queue_eda.h"

/*
Miguel Jesús Peñalver Carvajal
*/

template <class T>
class Eliminator : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	// Función que intercambia nodos dos a dos.
	void eliminate() {
		Nodo *cur = this->prim, *elim;

		// Siempre eliminamos el siguiente de current, de manera que avanzamos dos posiciones
		// de la cola inicial con cada iteración.
		while (cur != nullptr && cur->sig != nullptr) {
			elim = cur->sig;
			cur->sig = elim->sig;
			delete elim;
			--this->nelems;
			cur = cur->sig;
		}
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
inline std::ostream& operator<<(std::ostream& out, Eliminator<T> const l) {
	l.print(out);
	return out;
}