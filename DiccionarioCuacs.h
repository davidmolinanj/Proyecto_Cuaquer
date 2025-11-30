#ifndef DICCIONARIOCUACS_H
#define DICCIONARIOCUACS_H
#include <string>
#include <vector>
#include "cuac.h"
#include "TablaHash.h"
#include "ArbolAVL.h"

using namespace std;

class DiccionarioCuacs{
    friend class Fecha;
    friend class ArbolAVL;

    private:
    TablaHash tabla;
    ArbolAVL arbol;
    //TablaHash tabla;
    //Deberán estar ordenados por fecha

    public:
    void insertarCuacOrdenado (Cuac nuevo){
        Cuac *puntero_al_dato = tabla.insertar(nuevo);
        arbol.insertar(arbol.raiz, puntero_al_dato);
    }

    void followCuac(string nombre){
        tabla.followHash(nombre); 
    }

    void last (int N){
        int cont = 0;
        arbol.last(arbol.raiz, N, cont);
        cout << "Total: " << cont << " cuac" << endl;
    }

    void date (Fecha f1, Fecha f2){
        int cont = 0;
        arbol.date(arbol.raiz, f1, f2, cont);
        cout << "Total: " << cont << " cuac" << endl;
    }

    int numElem (){
        return tabla.numElem();
    }

    ArbolAVL getArbol(){
        return arbol;
    }

    TablaHash getTablaHash(){
        return tabla;
    }

};

#endif