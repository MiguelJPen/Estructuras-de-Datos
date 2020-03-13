#pragma once

#include <iostream>

#include "list_eda.h"

template <class T>
class PeopleList : public list<T> {
	using Nodo = typename list<T>::Nodo;
public:
	template <class Predicate>
	void remove_if(Predicate pred) {
		auto it = this->begin();
		while (it != this->end())
			if (pred(*it)) it = this->erase(it);
			else ++it;
	}

	// Printing function
	void print(std::ostream& out = std::cout) const {
		for (auto it = this->begin(); it != this->end(); ++it)
			out << *it << '\n';
	}
};

template <class T>
inline std::ostream& operator<<(std::ostream& out, PeopleList<T> const h) {
	h.print(out);
	return out;
}