
// Miguel Jesus Peñalver Carvajal (DG25)

/*
En este problema hago un programa que me diga si un arbol es pareado o no.
Un arbol es pareado si el número de nodos pares de su hijo derecho y de su hijo
izquierdo solo difieren en una unidad y, ademas, los subárboles que los componen
tambien son pareados.
Para resolver el problema uso recursión multiple, haciendo una llamada de la funcion
por cada hijo del arbol. Para los valores que devuelve la funcion uso un struct, 
con el que devuelvo el numero de nodos hijos pares del subarbol y un booleano que
representa si el subarbol es pareado. Primero tengo el caso base, que es el caso en 
el que el arbol sea vacio, con el que devuelvo 0 para el número de nodos pares y 
true, por ser pareado (caso vacio).
En caso de que no sea vacio, compruebo los subarboles hijos y trato sus valores de 
retorno: si ambos son pareados y las diferencias de nodos pares no difieren más que 
en una unidad, devuelvo la suma de nodos pares y true, por ser también pareado. En 
caso de que la raiz que estamos tratando sea par, sumamos una unidad al numero de nodos 
pares. Si vemos que los subarboles no son pareados o que el número de nodos difiere en 
mas de una unidad, devuelvo false, por lo que el arbol no es pareado.

Este problema es lineal en numero de nodos, es O(n), siendo n el numero
de nodos del arbol. Esto es por hacer una llamada recursiva por cada hijo,
por tanto, en todos los casos esta recursión va a ser lineal respecto al numero
de nodos.
*/


#include <iostream>                                                            
#include <fstream>               
#include <algorithm>
using namespace std;

#include "bintree_eda.h"



typedef struct {
	int numPares;
	bool isPareado;
} tPar;

tPar par(bintree<int> const& t) {
	if (t.empty()) return { 0, true };

	// LLamo primero a los hijos para llegar a las hojas del arbol.
	tPar left = par(t.left()), right = par(t.right());

	// Si son pareados y el numero de nodos hijos no difiere en más de una unidad...
	if (left.isPareado && right.isPareado && (left.numPares == right.numPares ||
		left.numPares + 1 == right.numPares || left.numPares == right.numPares + 1)) {
		// Si la raiz es par, sumamos una unidad.
		if (t.root() % 2 == 0) return { left.numPares + right.numPares + 1, true };
		else return { left.numPares + right.numPares, true };
	}

	return { 0, false };
}

bool pareado(bintree<int> const& t) {
	return par(t).isPareado;
}

void resuelveCaso() {
   auto arbol = leerArbol(-1);
   if (pareado(arbol))
      cout << "SI\n";
   else
      cout << "NO\n";
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   cin >> numCasos;
   
   for (int i = 0; i < numCasos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   //system("PAUSE");
#endif
   return 0;
}
