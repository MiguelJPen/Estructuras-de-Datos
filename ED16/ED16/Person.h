#pragma once

#include <iostream>
#include <string>

#include "list_eda.h"

/*
Miguel Peñalver Carvajal

En este problema recibimos una lista de personas con su edad y devolvemos los nombre que se encuentren
en un determinado rango que nos dan al comenzar el problema.
*/

class Person{
private:
	int age;
	std::string name;

public:
	Person() {}
	Person(int age, std::string name) {
		this->age = age;
		this->name = name;
	}
	~Person() {}

	int getAge() const { return age; }

	// Reading function
	void read(std::istream& input = std::cin) {
		int a;
		std::string n;

		input >> a;
		input.ignore();
		std::getline(input, n);
		*this = Person(a, n);
	}

	// Printing function
	void print(std::ostream& out = std::cout) const {
		out << name;
	}
};

inline std::istream& operator>>(std::istream& in, Person& a) {
	a.read(in);
	return in;
}

inline std::ostream& operator<<(std::ostream& out, Person const h) {
	h.print(out);
	return out;
}