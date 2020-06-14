#pragma once

#include <string>
#include <unordered_map>
#include <list>

using medico = std::string;
using paciente = std::string;

#define clave first
#define valor second


class consultorio {
	std::unordered_map<medico, std::list<paciente>> meds;

	// Un paciente puede esperar a varios médicos.
	using info_pac = std::unordered_map<medico, std::list<paciente>::iterator>;
	std::unordered_map<paciente, info_pac> pacs;
public:
   void alta_medico(medico const& m) { // O(1)
	   auto res = meds.insert({ m, {} });
	   if (!res.second)
		   throw std::domain_error(m + " repetido");
   }

   void pedir_consulta(paciente const& p, medico const& m) { // O(1)
	   auto it = meds.find(m);
	   if (it == meds.end())
		   throw std::domain_error(m + " no existe");

	   it->valor.push_back(p);
	   auto & ip = pacs[p];
	   auto itMP = ip.find(m);

	   if (itMP != ip.end())
		   throw std::domain_error(p + " no puede repetir con " + m);
	   it->valor.push_back(p);
	   ip[m] == --it->valor.end();
   }

   bool tiene_pacientes(medico const& m) const { // O(1)
	   auto it = meds.find(m);
		if (it == meds.end())
			throw std::domain_error(m + " no existe");
		else return !it->valor.empty();
   }

   paciente const& siguiente_paciente(medico const& m) const { // O(1)
	   auto it = meds.find(m);
	   if (it == meds.end())
		   throw std::domain_error(m + " no existe");
	   else if (it->valor.empty())
		   throw std::domain_error(m + " sin pacientes");
	   else
		   return it->valor.front();
   }

   void atender_consulta(medico const& m) { // O(1)
	   auto it = meds.find(m);
	   if (it == meds.end())
		   throw std::domain_error(m + " no existe");
	   else if (it->valor.empty())
		   throw std::domain_error(m + " sin pacientes");
	   pacs[it->valor.front()].erase(m);
	   it->valor.pop_front();
   }
   void abandonar_consulta(paciente const& p, medico const& m) { // O(1)
	   auto itM = meds.find(m);
	   if (itM == meds.end())
		   throw std::domain_error(m + " no existe");

	   auto itP = pacs.find(p);

	   if (itP == pacs.end())
		   throw std::domain_error(p + " no pidio consulta");

	   auto & ip = itP->valor;
	   auto itMP = ip.find(m);
	   if(itMP == ip.end())
		   throw std::domain_error(p + " no espera a " + m);

	   itM->valor.erase(itMP->valor);
	   ip.erase(itMP);
   }
};