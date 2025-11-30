#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <stdio.h>
#include <list>
#include <iostream>
#include "Nodo.h"
#include "cuac.h"

class ArbolAVL{

    friend class DiccionarioCuacs;

    private:
    Nodo *raiz;

    public:

    ArbolAVL();

    ~ArbolAVL(){
        raiz->~Nodo();
    }

    //RSI, RSD, RDI, RDD
    //void eliminar(Nodo *&nodo);
    void insertar(Cuac *c) {
        insertar(this->raiz, c);
     }
    void insertar(Nodo *&nodo, Cuac *c);
    
    void comprobarGiroMagistral(Nodo *&nodo);

    int getAltura(Nodo *nodo); //HECHO
    int balance(Nodo *nodo);    //HECHO

    void RSI(Nodo *&nodo);  //HECHO
    void RSD(Nodo *&nodo);  //HECHO
    void RDI(Nodo *&nodo);  //HECHO
    void RDD(Nodo *&nodo);  //HECHO
    
    void last(Nodo *nodo, int n, int &contador);       //HECHO
    int date(Nodo *nodo, Fecha f1, Fecha f2, int &contador);  //HECHO

    



};




#endif