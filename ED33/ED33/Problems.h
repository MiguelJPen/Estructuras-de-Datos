#pragma once

#include <iostream>
#include <set>
#include <string>

/*
Miguel Jesús Peñalver Carvajal
*/

class Problem {
private:
	std::string name;
	int numProblems;
	int totalTime;
	std::set<std::string> problems;

public:
	Problem() {
		numProblems = 0;
		totalTime = 0;
	}

	void setName(std::string n) {
		name = n;
	}
	void addProblem(std::string const& problem, int const& time) { // O(log(k)) siendo k el número de problemas resueltos correctamente
		if (problems.count(problem) == 0) {
			++numProblems;
			totalTime += time;
			problems.insert(problem);
		}
	}
	void addExtraTime(int t) {
		totalTime += t * 20;
	}
	bool notSolved(std::string problemName) {
		return problems.count(problemName) == 0;
	}
	bool operator<(Problem const& p) const {
		return (numProblems > p.numProblems || (numProblems == p.numProblems && totalTime < p.totalTime) ||
			(numProblems == p.numProblems && totalTime == p.totalTime && name < p.name));
	}
	void print(std::ostream& out = std::cout) const {
		out << name << ' ' << numProblems << ' ' << totalTime;
	}
};

inline std::ostream& operator<<(std::ostream& out, Problem const p) {
	p.print(out);
	return out;
}