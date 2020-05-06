#include <iostream>
#include <fstream>
#include <memory>
#include <cassert>
#include <stack>
#include <cctype>
#include <optional>
#include <sstream>
#include <map>
using namespace std;

#include "bintree_eda.h"

/*
Miguel Jesús Peñalver Carvajal

En este problema hemos hecho un intérprete de 'Calculón++'.
*/

/* ======================================================================
 * Analizador léxico/sintáctico del lenguaje Calculon++
 * Adaptado del original de Manuel Montenegro
 * ====================================================================== */


class Lexer {
public:
	Lexer(std::istream &in) : in(in) { }

	std::string peek() {
		if (next != "") {
			return next;
		}
		else {
			next = read_next();
			return next;
		}
	}

	std::string get() {
		std::string result = peek();
		next = "";
		return result;
	}

private:
	std::istream &in;

	std::string read_next() {
		ostringstream result;
		char current;
		in >> current;
		while (iswspace(current)) {
			in >> current;
		}


		if (isdigit(current)) {
			result << current;
			while (isdigit(cin.peek())) {
				in >> current;
				result << current;
			}
		}
		else if (isalpha(current)) {
			result << current;
			while (isalnum(cin.peek())) {
				in >> current;
				result << current;
			}
		}
		else if (current == '+' || current == '-' || current == '*' || current == ';' || current == '(' || current == ')') {
			result << current;
		}
		else if (current == ':') {
			result << current;
			in >> current;
			if (current != '=') throw std::domain_error("invalid token: :" + current);
			result << current;
		}
		else {
			throw std::domain_error("invalid_token: " + current);
		}

		return result.str();
	}

private:
	std::string next;
};

using AST = bintree<std::string>;

class Parser {
public:
	Parser(std::istream &in) : l(in) { }

	AST parse() {
		return S();
	}

private:
	Lexer l;

	bool is_identifier(const std::string &token) {
		return (!token.empty() && isalpha(token[0]));
	}

	bool is_identifier_or_number(const std::string &token) {
		return (!token.empty() && isalnum(token[0]));
	}


	AST S() {
		std::string identifier = l.get();
		if (!is_identifier(identifier)) throw std::domain_error("identifier expected, found " + identifier);

		std::string equal = l.get();
		if (equal != ":=") throw std::domain_error(":= expected, found " + equal);

		AST rhs = E();

		std::string semicolon = l.get();
		if (semicolon != ";") throw std::domain_error("; expected, found " + semicolon);

		return { { identifier }, ":=", rhs };
	}

	AST E() {
		AST term = T();
		return Ep(term);
	}

	AST Ep(const AST &left) {
		std::string op = l.peek();
		if (op == "+" || op == "-") {
			l.get();
			AST term = T();
			return Ep({ left, op, term });
		}
		else {
			return left;
		}
	}

	AST T() {
		AST factor = F();
		return Tp(factor);
	}

	AST Tp(const AST &left) {
		std::string op = l.peek();
		if (op == "*") {
			l.get();
			AST factor = F();
			return Tp({ left, "*", factor });
		}
		else {
			return left;
		}
	}

	AST F() {
		std::string next = l.get();
		if (is_identifier_or_number(next)) {
			return { next };
		}
		else if (next == "(") {
			AST inner = E();
			std::string closing = l.get();
			if (closing != ")") throw std::domain_error(") expected, found " + closing);
			return inner;
		}
		else {
			throw std::domain_error("number or identifier expected, found " + next);
		}
	}
};

// Función que lee una instrucción de la entrada y devuelve su AST
AST parse(std::istream &in = std::cin) {
	return Parser(in).parse();
}

// Esta operación tiene coste constante.
long long int aply(char operation, long long int l, long long int r) {
	if (operation == '+')
		return l + r;
	if (operation == '-')
		return l - r;
	return l * r;
}

// Esta operación tiene coste O(n·log(k)), siendo n el número de nodos del árbol y k el número de variables en el mapa.
long long int operate(AST const& a, map<string, long long int> const& variables) {
	if (isdigit(a.root()[0]))
		return stoi(a.root());
	if (a.root().size() == 1 && (a.root() == "+" || a.root() == "-" || a.root() == "*")) {
		long long int left = operate(a.left(), variables), right = operate(a.right(), variables);
		return aply(a.root()[0], left, right);
	}
	
	return variables.at(a.root());
}

bool resuelveCaso() {
	long long int n;
	
	std::cin >> n;
	if (n == 0) return false;

	map<string, long long int> variables;
	while (n--) {
		AST a = parse(cin);
		variables[a.left().root()] = operate(a.right(), variables);
	}

	for (auto it : variables) {
		cout << it.first << " = " << it.second << '\n';
	}
	cout << "---\n";

	return true;
}


int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
