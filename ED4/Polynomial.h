#pragma once

#include <iostream>
#include <vector>
#include <math.h>

#include "Monomy.h"

class Polynomial {
private:
	// This vector represents a polinomy.
	std::vector<Monomy> pol;

public:
	// We read the polinomy in the constructor.
	Polynomial() {
		Monomy m;

		cin >> m;
		if (std::cin.fail()) throw domain_error("Invalid data.");

		// We check if we have reached the end of the monomies (0, 0).
		while (m.isValid()) {
			addMonomy(m);
			std::cin >> m;
		}
	}
	~Polynomial() {}

	// Method to add a monomy.
	void addMonomy(Monomy m) {
		unsigned int i = 0;

		// By this function we add the monomies in order (according to the exponent) or add the new coeficient.
		while (i < pol.size() && m.getExp() > pol.at(i).getExp())
			++i;
		if (i < pol.size() && m.getExp() == pol.at(i).getExp()) 
			pol.at(i).addCoef(m.getCoef());
		else {
			if (i != pol.size())
				pol.insert(pol.begin() + i, m);
			else pol.push_back(m);
		}
	}

	// Method to get the value of the polinomy for a certain value (val).
	int valoration(int const& val) {
		int ret = 0;
		
		for (unsigned int i = 0; i < pol.size(); ++i)
			ret += pol.at(i).getCoef() * pow(val, pol.at(i).getExp());
		return ret;
	}
};