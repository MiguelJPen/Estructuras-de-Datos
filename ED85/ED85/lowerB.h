#pragma once
#include <vector>

#include "set_eda.h"

/*
Miguel Jesús Peñalver Carvajal
*/

template <class T, class Comparator = std::less<T>>
class lowerB : public set<T, Comparator> {

public:
	std::pair<bool, T> lower_bound(T const& e) const;

};

template <class T, class Comparator>
inline std::pair<bool, T> lowerB<T, Comparator>::lower_bound(T const & e) const {
	auto it = this->begin();

	while (it != this->end() && *it < e) {
		++it;
	}
	if (it == this->end()) return std::make_pair(false, e);
	return std::make_pair(true, *it);
}