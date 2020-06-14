
// Miguel Jesús Peñalver Carvajal (DG25)

/*
En este problema entremezclamos dos deque, de manera que, en la lista resultante, el primer elemento sea de la primera,
el segundo elemento de la segunda lista, el tercero de la primera... alternamos los elementos en la lista resultante.
Dispongo de dos nodos 'current', uno para cada lista, que son los que modifico para que apunten a los siguienntes nodos.
Además, guardo los siguientes elementos de los dos anteriores en dos variables 'aux' y 'aux2', que me sirven también para salir
del bucle en caso de que éstos apuntes al fantasma de su lista correspondiente, indicando que se ha llegado al final.
En caso de que se haya llegado al final y no se hayan acabado los elementos de la segunda lista, empalmamos la lista que queda
al final de la primera. Se puede encontrar una explicación con más detalle en el código de la función.

El coste de esta solución, en el caso peor, es de O(n + m), siendo n y m el número de elementos de la primera 
y la segunda lista. Este caso peor solo se alcanza cuando n y m son iguales.
*/


#include <iostream>                              
#include <fstream>               
#include <algorithm>
using namespace std;

#include "deque_eda.h"

class EntremezclarListas : public deque<int> {
public:
   // imprime la lista
	// El coste de esta función es O(n), siendo n el número de elementos de la lista.
   void print(std::ostream& o = std::cout) const {
	   Nodo* aux = this->fantasma->sig;
	   while (aux != this->fantasma) {
		   o << aux->elem << " ";
		   aux = aux->sig;
	   }
   }

   // modifica this para entremezclar sus elementos con los de other
   void entremezclar(EntremezclarListas & other) {
	   Nodo *aux = this->fantasma->sig;
	   Nodo *aux2 = other.fantasma->sig;
	   Nodo *current, *current2;

	   while (aux != this->fantasma && aux2 != other.fantasma) {
		   /*
		   En esta sección guardo el elemento que vamos a modificar de la primera lista en el nodo
		   'current' y el elemento de la segunda, al que va a apuntar current, en el nodo 'current2'.
		   Además, dispongo de dos variables auxiliares, 'aux' y 'aux2', que son las que utilizo para 
		   guardar el siguiente nodo de current de la primera y la segunda lista.
		   */
		   current = aux;
		   current2 = aux2;
		   aux = aux->sig;
		   aux2 = aux2->sig;

		   /*
		   Modifico los nodos los punteros de 'current' y 'current2' para introducir el nodo de la segunda
		   lista en la primera.
		   */
		   current->sig = current2;
		   current2->ant = current;
		   current2->sig = aux;
		   aux->ant = current2;

	   }
	   /* Este es el caso tratado aparte, en el que la primera lista se termina, pero aún quedan elementos en la 
	   segunda. En este caso, sencillamente hacemos apuntar el úlitmo nodo de la primera lista al nodo 'aux2' de la
	   segunda, que será el primer elemento de esta. Posteriormente, hacemos que el fantasma de la primera lista apunte
	   apunte al último elemento de la segunda lista y el último elemento de la segunda lista apunte al fantasma de la primera.
		*/
	   if (aux == this->fantasma && aux2 != other.fantasma) {
		   aux->ant->sig = aux2;
		   aux2->ant = aux->ant;

		   aux->ant = other.fantasma->ant;
		   other.fantasma->ant->sig = aux;
	   }
	   /*
	   Sumamos el número de elementos de la segunda lista a la primera y hacemos que el fantasma de la segunda apunte a sí 
	   mismo, ya que no tiene elementos.
	   */
	   this->nelems += other.nelems;
	   other.fantasma->sig = other.fantasma;
	   other.fantasma->ant = other.fantasma;
	   other.nelems = 0;
   }
   
};


/////////////////////////////////////////////////////////
// de aquí hacia abajo NO se puede modificar nada

inline std::ostream& operator<<(std::ostream & o, EntremezclarListas const& a) {
   a.print(o);
   return o;
}

EntremezclarListas leerLista() {
   EntremezclarListas lista;
   int n, val;
   cin >> n; // tamaño
   while (n--) {
      cin >> val;
      lista.push_back(val);
   }
   return lista;
}

void resuelveCaso() {
   auto lista1 = leerLista();
   auto lista2 = leerLista();
   
   lista1.entremezclar(lista2);
   
   cout << lista1 << '\n';
}


int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int casos;
   cin >> casos;
   for (int i = 0; i < casos; ++i) {
      resuelveCaso();
   }

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
 //  system("PAUSE");
#endif
   return 0;
}
