
#ifndef consultorio_h
#define consultorio_h
#include <string>

using medico = std::string;
using paciente = std::string;

#define clave first
#define valor second


class consultorio {
public:
   void alta_medico(medico const& m) {
     
   }

   void pedir_consulta(paciente const& p, medico const& m) {
     
   }

   bool tiene_pacientes(medico const& m) const {
      
   }

   paciente const& siguiente_paciente(medico const& m) const {
     
   }

   void atender_consulta(medico const& m) {
     
   }
   
   void abandonar_consulta(paciente const& p, medico const& m) {

   }
};

#endif
