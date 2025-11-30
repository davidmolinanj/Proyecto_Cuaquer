#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <stdio.h>
#include <list>
#include <iostream>
#include "Nodo.h"
#include "cuac.h"

class ArbolAVL{

    private:
    Nodo *raiz;

    public:

    ArbolAVL();     //es vital hacer el constructor del árbol (que empezaría vacío)
    ~ArbolAVL();
    //RSI, RSD, RDI, RDD
    void insertar(Cuac *clave); #TODO
    //void eliminar(Nodo *&nodo);
    void comprobarGiroMagistral(Nodo *nodo);

    int getAltura(Nodo *nodo); #TODO
    int balance(Nodo *nodo);

    void RSI(Nodo *&nodo);
    void RSD(Nodo *&nodo);  #TODO
    void RDI(Nodo *&nodo);  #TODO
    void RDD(Nodo *&nodo);  #TODO
    
    void last(int n);       #TODO: pasar a c++
    void date(Fecha f1, Fecha f2);  #TODO:pasar a c++

    



};



#endif