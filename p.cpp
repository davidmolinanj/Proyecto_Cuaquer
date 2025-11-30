#include <iostream>
#include <string>
#include <stdio.h>
#include "cuac.h"
#include "TablaHash.h"
using namespace std;

DiccionarioCuacs Dict;
Cuac c;
int n = 0;

void interprete(string comando){

        if (comando=="mcuac"){
            n++;
            cout << n << " " << "cuac" << endl;
            c.procesar_mcuac();
            Dict.insertarCuacOrdenado(c);
        }
        
        else if (comando=="pcuac"){
            n++;
            cout << n << " " << "cuac" << endl;
            c.procesar_pcuac();
            Dict.insertarCuacOrdenado(c);
        }

        else if (comando=="last"){
            int numero;
            cin >> numero;
            cout << comando << " " << numero << endl;
            Dict.last(numero);
        }

        else if (comando=="date"){
            Fecha fecha1;
            Fecha fecha2;
            fecha1.setFecha();
            fecha2.setFecha();
            cout << comando << " ";
            fecha1.mostrar();
            cout << " ";
            fecha2.mostrar();
            cout << endl;
            Dict.date(fecha1,fecha2);
        }

        else if (comando=="tag"){
            string poya;
            cin >> poya;
            cout << comando << " " << poya << endl;
            cout << "1. ";
            c.escribir();
            cout << "Total: 1 cuac" << endl;
        }

        else if (comando=="follow"){
          string nombre;
          cin >> nombre;
          cout << comando << " " << nombre << endl;
          Dict.followCuac(nombre);
        }
    }

int main (void) {
   string comando;
   while (cin >> comando && comando != "exit"){
      interprete(comando);
   }

   Dict.getArbol().~ArbolAVL();
   Dict.getTablaHash().~TablaHash();
   return 0;
      
}
