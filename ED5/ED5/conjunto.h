//
//  conjunto.h
//

#ifndef conjunto_h
#define conjunto_h

#include <stdexcept>  // std::domain_error
#include <utility>    // std::move
#include <algorithm>

template <class T>
class set {
public:
    set(int tam = TAM_INICIAL); // constructor
    set(set<T> const& other); // constructor por copia
    set<T> & operator=(set<T> const& other); // operador de asignación
    ~set(); // destructor
    void insert(T e);
    bool contains(T e) const;
    void erase(T e);
    bool empty() const;
    int size() const;

	//Funciones adicionales añadidas:
	T minimo() const{
		if (empty()) throw std::domain_error(""); //Lanzamos excepciones cuando realizamos operaciones sobre conjuntos vacios
		return datos[contador - 1];
	}
	void erase_min() {
		// Como el conjunto está ordenado de mayor a menor, para borrar el menor borramos el último elemento.
		if (empty()) throw std::domain_error(""); //Lanzamos excepciones cuando realizamos operaciones sobre conjuntos vacios
		erase(datos[contador - 1]);
	}
private:
    const static int TAM_INICIAL = 8;
    int contador;
    int capacidad;
    T * datos;
    void amplia();
    void libera();
    void copia(set<T> const& other);
};

template <class T>
set<T>::set(int tam) : contador(0), capacidad(tam), datos(new T[capacidad]) {}

template <class T>
set<T>::~set() {
   libera();
}

template <class T>
void set<T>::libera() {
   delete[] datos;
}

/** Constructor por copia */
template <class T>
set<T>::set(set<T> const& other) {
   copia(other);
}

/** Operador de asignación */
template <class T>
set<T> & set<T>::operator=(set<T> const& other) {
   if (this != &other) {
      libera();
      copia(other);
   }
   return *this;
}

template <class T>
void set<T>::copia(set<T> const& other) {
   capacidad = other.capacidad;
   contador = other.contador;
   datos = new T[capacidad];
   for (int i = 0; i < contador; ++i)
      datos[i] = other.datos[i];
}

template <class T>
void set<T>::insert(T e) {
	//Redefinicion del insert, de manera que los elementos queden ordenados de mayor a menor en el conjunto.
    if (!contains(e)) {
        if (contador == capacidad)
            amplia();
        
		int p = contador;
		while (p > 0 && datos[p - 1] < e) {
			datos[p] = datos[p - 1];
			--p;
		}
		datos[p] = e;
        ++contador;
    }
	//Coste asintotico de la funcion->n(Número de elementos del array) 
}

template <class T>
bool set<T>::contains(T e) const {
	// Usamos la función de la clase algorithm 'binary_search' para ver si contiene un elemento 
	// de tipo T el conjunto.
    return std::binary_search(datos, datos + contador, e, std::greater<T>());
}

template <class T> 
void set<T>::amplia() {
    T * nuevos = new T[2*capacidad];
    for (int i = 0; i < capacidad; ++i)
        nuevos[i] = std::move(datos[i]);
    delete[] datos;
    datos = nuevos;
    capacidad *= 2;
}

template <class T>
void set<T>::erase(T e) {
	int i = lower_bound(datos, datos + contador, e, std::greater<T>()) - datos;
    if (i < contador && datos[i] == e) {
		while (i + 1 < contador) {
			datos[i] = datos[i + 1];
			++i;
		}
		--contador;
    }
}


template <class T>
bool set<T>::empty() const {
   return contador == 0;
}

template <class T>
int set<T>::size() const {
   return contador;
}

#endif // conjunto_h
