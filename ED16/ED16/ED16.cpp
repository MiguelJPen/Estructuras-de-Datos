#include <iostream>

#include "PeopleList.h"
#include "Person.h"

bool ageInRange(Person p, int minAge, int maxAge) {
	return minAge <= p.getAge() && p.getAge() <= maxAge;
}

bool resuelveCaso() {
	int n, minAge, maxAge;
	std::cin >> n >> minAge >> maxAge;
	if (n == 0 && minAge == 0 && maxAge == 0) return false;

	PeopleList<Person> l;
	for (int i = 0; i < n; ++i) {
		Person p;
		std::cin >> p;
		l.push_back(p);
		l.remove_if([minAge, maxAge](Person p) {return !ageInRange(p, minAge, maxAge); });
	}
	std::cout << l << "---\n";
	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}