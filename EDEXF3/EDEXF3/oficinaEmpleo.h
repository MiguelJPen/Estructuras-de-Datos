
// Miguel Jesús Peñalver Carvajal

/*
PE = número máximo de empleos para los que está cualificada una persona.

En este problema realizo un programa para la gestión de una oficina
de empleo, con la que recibo nombres de personas cualificadas para
realizar ciertos empleos, los cuales almaceno en orden, según cada 
empleo. Para almacenar los datos empleo:
- Un mapa desordenado con clave un nombre de una persona y valor 
un conjunto para almacenar los empleos para los que una persona 
está cualificada, de esta manera dispongo de una lista ordenada 
alfabéticamente de los empleos. 
- Un mapa desordenado con clave un empleo y valor una lista de 
personas que está cualificadas para un empleo determinado, de esta
manera puedo mantener el orden de solicitud de las personas para
un empleo.
- Un mapa desordenado que tiene como clave un empleo y valor otro
mapa desordenado con clave un nombre de una persona y valor un
iterador a la lista del mapa anterior.

Ahora voy a explicar cada operación de las que he diseñado:
- La operación altaOficina(persona, empleo) añade a los mapas implementados la información
que recibe. Esta operación tiene coste log(PE), debido a la inserción en 
en el conjunto asociado de empleos a cada persona.
- La operación ofertaempleo(empleo) devuelve la persona que más tiempo
lleva solicitando el empleo que recibe. En este caso, debemos eliminar
todos los datos de la persona que hayamos almacenado y, en caso de que
los empleos para los que estaba cualificada también se queden sin personas
asociadas, también se eliminan, por este motivo esta función tiene 
O(PE).
- La operación listadoEmpleos(persona) devuelve una lista ordenada 
alfabéticamente con los empleos para los que está cualificada una 
persona. Esta función tiene coste lineal en el número de empleos 
para los que está cualificada la persona, ya que debo transformar 
el conjunto ordenado alfabéticamente a la lista que devuelvo, también
ordenada.
*/

#ifndef OFICINAEMPLEO
#define OFICINAEMPLEO

#include <iostream>               
#include <string>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

using persona = string;
using empleo = string;

class oficinaEmpleo {
   
	unordered_map<persona, set<empleo>> persEmpleo;
	unordered_map<empleo, list<persona>> empleoPers;
	unordered_map<empleo, unordered_map<persona, list<persona>::iterator>> empleoPersIt;

public:
	void altaOficina(persona const& p, empleo const& e) { // O(log PE)
		if (persEmpleo[p].count(e) == 0) {
			persEmpleo[p].insert(e);
			empleoPers[e].push_front(p);
			empleoPersIt[e][p] = empleoPers[e].begin();
		}
	}
	persona ofertaEmpleo(empleo const& e) { // O(PE)
		if (empleoPers.count(e) == 0) throw domain_error("No existen personas apuntadas a este empleo");

		persona ret = empleoPers[e].back();

		for (empleo em : persEmpleo[ret]) {
			empleoPers[em].erase(empleoPersIt[em][ret]);
			if (empleoPers[em].size() == 0) empleoPers.erase(em);
		}

		persEmpleo.erase(ret);

		return ret;
	}
	list<empleo> listadoEmpleos(persona const& p) const { // O(PE)
		if (persEmpleo.count(p) == 0) throw std::domain_error("Persona inexistente");

		list<empleo> ret;
		for (empleo e : persEmpleo.at(p)) ret.push_back(e);

		return ret;
	}
};
#endif
