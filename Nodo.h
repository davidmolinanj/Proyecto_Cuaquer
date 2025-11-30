#ifndef NODO_H
#define NODO_H
#include <stdio.h>
#include <iostream>
//#include "TablaHash.h"
//#include "DiccionarioCuacs.h"
#include "cuac.h"
using namespace std;

class Nodo{
    
    friend class ArbolAVL;
    
    private:
        Cuac *clave;
        Nodo *hijoizq;
        Nodo *hijoder;
        int altura;
    
    public:
    Nodo(){
        clave = nullptr;
        hijoizq = nullptr;
        hijoder = nullptr;
        altura = 0;      
    }

    ~Nodo(){
        /*if(altura > 0){
            hijoder->~Nodo();
            hijoizq->~Nodo();
            delete clave;

        }*/
        delete hijoder;
        delete hijoizq;
    }

    
};



#endif