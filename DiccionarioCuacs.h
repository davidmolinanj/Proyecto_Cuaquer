#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H
#include <string>
#include <vector>
#include "cuac.h"
#include "TablaHash.h"

using namespace std;



class DiccionarioCuacs{
    friend class Fecha;

    private:
    TablaHash tabla;
    //TablaHash tabla;
    //Deberán estar ordenados por fecha

    public:
     void insertarCuacOrdenado (Cuac nuevo){
        tabla.insertar(nuevo);
     }

     void followCuac(string nombre){
        tabla.followHash(nombre); 
    }
     //void last (int N);
     //void date (Fecha f1, Fecha f2);
     int numElem (){
        return tabla.numElem();
    }
};

#endif