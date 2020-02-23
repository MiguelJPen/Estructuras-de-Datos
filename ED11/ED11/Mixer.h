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
		Nodo *aux = this->prim;
		Nodo *aux2 = l2.prim;
		Nodo *auxSig = (aux == nullptr ? nullptr : aux->sig), *aux2Sig;

		if (aux2->elem < aux->elem) {
			this->prim = aux2;
			auxSig = aux->sig;
			aux2Sig = aux2->sig;
			aux2->sig = aux;
			aux = auxSig;
			auxSig = aux->sig;
			aux2 = aux2Sig;
			l2.prim = aux2Sig;
			--l2.nelems;
			++this->nelems;
		}
		while (!l2.empty()) {
			if (auxSig == nullptr) {
				aux->sig = aux2;
				aux = aux->sig;
				aux2 = aux2->sig;
				l2.prim = aux2;
				--l2.nelems;
				++this->nelems;
			}
			else if (aux2->elem > aux->elem && aux2->elem < auxSig->elem) {
				auxSig = aux->sig;
				aux2Sig = aux2->sig;
				aux->sig = aux2;
				aux2->sig = auxSig;
				aux = auxSig;
				auxSig = aux->sig;
				aux2 = aux2Sig;
				l2.prim = aux2Sig;
				--l2.nelems;
				++this->nelems;
			}
			else {
				aux = aux->sig;
				auxSig = aux->sig;
			}
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
inline std::ostream& operator<<(std::ostream& out, Mixer<T> const l) {
	l.print(out);
	return out;
}