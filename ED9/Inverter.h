#pragma once

#include <iostream>

#include "deque_eda.h"

/*
Miguel Peñalver Carvajal
*/

template <class T>
class Inverter : public deque<T> {
	using Nodo = typename deque<T>::Nodo;
public:
	Inverter() {
		deque<T>();
	}
	~Inverter() {}

	// Inversion function
	// Esta función tiene orden n, ya que pasa una vez por cada elemento de la lista.
	void invert() {
		Nodo *nodo = this->fantasma->ant;
		Nodo *aux;

		// Cambiamos los punteros anterior y siguiente de cada nodo de la lista.
		while (nodo != this->fantasma) {
			aux = nodo->ant;
			nodo->ant = nodo->sig;
			nodo->sig = aux;

			nodo = nodo->sig;
		}
		// Cambiamos los punteros anterior y siguiente del fantasma.
		aux = this->fantasma->sig;
		this->fantasma->sig = this->fantasma->ant;
		this->fantasma->ant = aux;
	}

	// Printing function
	void print() {
		Nodo *aux = this->fantasma->sig;
		while (aux != this->fantasma) {
			std::cout << aux->elem << ' ';
			aux = aux->sig;
		}
		std::cout << '\n';
	}
};