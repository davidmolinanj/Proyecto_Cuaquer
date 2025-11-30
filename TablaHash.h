#ifndef TABLAHASH_H
#define TABLAHASH_H
#include <list>
#include "DiccionarioCuacs.h"
#include "cuac.h"

class TablaHash{

    friend class Cuac;
    private:
    //tiene pinta de que una cerrada es mejor, si hay muchos usuarios.
    //tabla dispersion cerrada de listas de cuacs
    list<list<Cuac>> *tabla; // == vector<Cuac> lista[]; vector<Cuac> *tabla
    int tam; //tamaño de la tabla
    int nElem;  //numero de elementos en la tabla

    /*private:
     ...
     int nElem;
  public:
     TablaHash ();
     ~TablaHash ();
     void insertar (Cuac nuevo);
     void consultar (string nombre);
     int numElem (void) { return nElem; }
};
*/
    public:
    TablaHash(){
        tam = 5003;
        tabla = new list<list<Cuac>>[tam](); 
        nElem = 0;
    };
    
    ~TablaHash(){
        delete[] tabla;
    };

    void insertar(Cuac nuevo);  //inserta un nuevo cuac en la tabla
    
    /*void expandir();*/

    unsigned int funciones_hash(string nombre_clave); //funcion de dispersion para asignar la posicion en la tabla

    /*unsigned int funcion_redispersion(string nombre_clave, int iteracion);*/ //al final lo vamos a hacer con disp. abierta

    void followHash(string nombre_dado); //muestra los cuacs de un usuario dado

    int numElem(); 
};    

#endif