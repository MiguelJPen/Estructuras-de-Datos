
// Miguel Jesús Peñalver Carvajal

#include <iostream>               
#include <string>
#include <fstream>
using namespace std;

#include "oficinaEmpleo.h"


bool resuelveCaso() {
   string orden, nom, emp;
   cin >> orden;
   if (!cin)
      return false;
   
   oficinaEmpleo paro;
   
   while (orden != "FIN") {
      try {
         if (orden == "altaOficina") {
            cin >> nom >> emp;
            paro.altaOficina(nom, emp);
         } else if (orden == "ofertaEmpleo") {
            cin >> emp;
            auto afortunado = paro.ofertaEmpleo(emp);
            cout << emp << ": " << afortunado << '\n';
         } else if (orden == "listadoEmpleos") {
            cin >> nom;
            auto caps = paro.listadoEmpleos(nom);
            cout << nom << ":";
            for (auto c : caps) {
               cout << ' ' << c;
            }
            cout << '\n';
         }
      } catch (domain_error e) {
         cout << "ERROR: " << e.what() << '\n';
      }
      cin >> orden;
   }
   cout << "---\n";
   return true;
}


int main() {
   
// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   // system("PAUSE");
#endif

   return 0;
}
