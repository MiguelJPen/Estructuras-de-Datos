#pragma once

#include "deque_eda.h"

template <class T>
class Inverter : public deque<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	Inverter() {
		deque<T>();
	}
	~Inverter() {}

	// Inversion function
	void invert() {
		Nodo *nodo = fantasma->ant;
		Nodo *aux = ;

		while (nodo != fantasma->sig) {

		}
		aux = fantasma->sig;
		fantasma->sig = fantasm->ant;
		fantasma->ant = aux;
	}

	// Printing function
	void print() {
		Nodo *aux = fantasma->sig;
		for (int i = 0; i < nElems; ++i) {

		}
	}
};