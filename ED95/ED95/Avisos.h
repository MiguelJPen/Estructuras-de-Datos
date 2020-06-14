#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

#include "Time.h"

// Miguel Jesús Peñalver Carvajal

using aviso = std::string;

class Avisos {
private:
	std::unordered_map<aviso, std::vector<Time>> m;

public:
	void annadir(aviso const& a, Time const& t) { // O(1)
		m[a].push_back(t);
	}
	Time consultar(aviso const& a, long int n) { // O(1)
		if (m.count(a) == 0 || m[a].size() < n)
			throw std::domain_error("Not found");
		return m[a].at(--n);
	}
};