#include <stdio.h>
#include <math.h>
#include <list>
#include <iostream>
#include "TablaHash.h"
#include "DiccionarioCuacs.h"

using namespace std;

//Nos dice en que posición del array de la tabla hash debe ir el elemento con clave nombreClave
unsigned int TablaHash::funciones_hash(string nombreClave){
    unsigned int suma = 0;
    for(int i = 0; i < nombreClave.length(); i++){
        suma = (31 * suma + nombreClave[i]) % tam; //31 es primo que yo sepa. podemos usarlo. (30 + 1)
    }
    return suma;
}

Cuac *TablaHash::insertar(Cuac nuevoCuac){
    //list<list<Cuac>> *tabla
    unsigned int h_k = funciones_hash(nuevoCuac.nombre);

    list<list<Cuac>>::iterator it = tabla[h_k].begin();

    while((it != tabla[h_k].end()) && (it->begin()->nombre != nuevoCuac.nombre)){
        it++;
    }

    Cuac* puntero_retorno = nullptr;    //NUEVO

    //si has llegado al final, entonces insertas tu cuac e incrementas nElem (usr nuevo)
    if(it == tabla[h_k].end()){
        list<Cuac> nuevaLista;
        nuevaLista.push_back(nuevoCuac);
        tabla[h_k].push_back(nuevaLista);
        nElem++;
        puntero_retorno = &tabla[h_k].back().back(); //NUEVO it.end().end() ==> devuelve referencia al cuac 
    }

    //y si no, pues te la metes dentro en insertarCuacOrdenado (usr ya existe)
    //estamos viendo en que posicion de los nombres está
    else{
        //es_mayor == ha ocurrido antes, es_menor == ha ocurrido después
        list<Cuac>::iterator it2;
        Fecha actual = nuevoCuac.devolver_fecha();
        it2 = it->begin();
        
        //voy a buscar la posición correcta para insertar el cuac nuevoCuac
        while(it2 != it->end() && it2->fecha.es_mayor(nuevoCuac.fecha)){
            it2++;     
        }

        //antiguo insertar cuac ordenado primero por fecha, luego por texto, luego por nombre. (no hay dos cuacs con todo iguales)
        while(it2 != it->end() && (it2->fecha.es_igual(actual))){
        
            if(it2->texto < nuevoCuac.texto){
                it2++;
            }
            else{ // texto[i] > texto actual || nombre[i] == actual || nombre[i] > nombre actual
                break;
            }
        }

        auto it_insertar = it->insert(it2, nuevoCuac);
        nElem++;
        
        // Convertimos iterador a puntero
        puntero_retorno = &(*it_insertar);
        
    }
    return puntero_retorno;
    
    /* if(nElem/tam > 1.5){
        expandir();
    }*/
}

/*void TablaHash::expandir(){ //TENEMOS QUE IMPLEMENTARLO??
    //necesitamos aumentar el tamaño del array máximo a por lo menos 2B + 1, para que sea
    //un número impar.
}*/ 

void TablaHash::followHash(string nombre){
    unsigned int h_k = funciones_hash(nombre);
    int contador = 0;

    if (tabla[h_k].empty()) {
        cout << "Total: " << contador << " cuac" << endl; 
        return;
    }

    list<list<Cuac>>::iterator it;
    list<Cuac>::iterator it2;
    it = tabla[h_k].begin();
    while((it != tabla[h_k].end()) && (it->begin()->nombre != nombre)){
        it++;
    }
    //si hemos llegado al final en it, no hay nombre. sin mas.
    //nos saltamos ese caso y miramos el siguiente: el nombre se encuentra.
    
    if(it != tabla[h_k].end()){
        int i = 0;
        for(it2 = it->begin(); i < it->size(); i++){
            contador++;
            cout << contador << ". ";
            it2->escribir();
            i++;
        }
    }
    cout << "Total: " << contador << " cuac" << endl; 
}


    int TablaHash::numElem(){
        return nElem;
}
