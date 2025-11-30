#include "Nodo.h"
#include "ArbolAVL.h"
#include <math.h>
using namespace std;



/*TODO: habrá que hacer que cuando se crear un nodo en la tabla hash, el nodo apunte a la dirección de la 
tabla hash y se cree así el árbol*/
 

int ArbolAVL::getAltura(Nodo *nodo){
    if(nodo == nullptr){ 
        return -1;
    }
    return nodo->altura;
} 

void ArbolAVL::insertar(Nodo *&nodo, Cuac *c){
    if(nodo == nullptr){ //raiz
        nodo->clave = c;
        /*nodo->hijoder = nullptr;
        nodo->hijoizq = nullptr;<
        nodo->altura = 0;*/
        //creo que esa cosa lo hace ya nuestro constructor.
        return;
    }
    
    else if(c->devolver_fecha().es_menor(nodo->clave->devolver_fecha())){
        insertar(nodo->hijoizq, c);
    }

    else if(c->devolver_fecha().es_mayor(nodo->clave->devolver_fecha())){
        insertar(nodo->hijoder, c);
    }

    else{
        return; //si ocurre esto, la hemos cagado fuerte
    }

    nodo->altura = 1 + max(getAltura(nodo->hijoizq),getAltura(nodo->hijoder));
    comprobarGiroMagistral(nodo);   //Comprueba si hay que hacer una rotación
}






void ArbolAVL::RSI(Nodo *&nodo){
    if(nodo == nullptr || nodo->hijoizq == nullptr){
        return;
    }   //esto lo pongo por si acaso el comprobarGiro funciona como el culo.

    Nodo *nodoB = nodo->hijoizq;
    nodo->hijoizq = nodoB->hijoder;
    nodoB->hijoder = nodo;
    nodo->altura  = 1 + max(getAltura(nodo->hijoizq), getAltura(nodo->hijoder));    //He usado el getAltura
    nodoB->altura = 1 + max(getAltura(nodoB->hijoizq), getAltura(nodoB->hijoder));
    nodo = nodoB;
}   

void ArbolAVL::RSD(Nodo *&nodo){ //nodo = A y nodo->hijoder = B
    if(nodo == nullptr || nodo->hijoder == nullptr){
        return;
    }   //esto lo pongo por si acaso el comprobarGiro funciona como el culo.

    Nodo *nodoB = nodo->hijoder;
    nodo->hijoder = nodoB->hijoizq;
    nodoB->hijoizq = nodo;
    nodo->altura = 1 + max(getAltura(nodo->hijoizq), getAltura(nodo->hijoder));
    nodoB->altura = 1 + max(getAltura(nodoB->hijoizq), getAltura(nodoB->hijoder));
    nodo = nodoB;
}

void ArbolAVL::RDI(Nodo *&nodo){
    RSD(nodo->hijoizq);
    RSI(nodo);
}

void ArbolAVL::RDD(Nodo *&nodo){
    RSI(nodo->hijoder);
    RSD(nodo);
}

int ArbolAVL::balance(Nodo *nodo){
    if(nodo == nullptr){
        return -1;
    }  
    return (getAltura(nodo->hijoizq) - getAltura(nodo->hijoder));
}   

void ArbolAVL::comprobarGiroMagistral(Nodo *&nodo){
    if(balance(nodo) > 1 && balance(nodo->hijoizq) >= 0){
        RSI(nodo);
    }
    else if(balance(nodo) > 1 && balance(nodo->hijoizq) < 0){
        RDI(nodo);
    }
    else if(balance(nodo) < -1 && balance(nodo->hijoder) > 0){
        RDD(nodo);
    }
    else if(balance(nodo) < -1 && balance(nodo->hijoder) <= 0){
        RSD(nodo); 
    }   
}
/*  1 balance(A) > 1 y balance(A.izq) ≥ 0 → RSI(A)
    2 balance(A) > 1 y balance(A.izq) < 0 → RDI(A)
    3 balance(A) < −1 y balance(A.der) > 0 → RDD(A)
    4 balance(A) < −1 y balance(A.der) ≤ 0 → RSD(A)*/


void ArbolAVL::last(Nodo *nodo, int tope, int &cont){   //NOS FALTAN MOVIDAS
    if (cont >= tope) {
        return ;
    }

    if(nodo->hijoder != nullptr){
        last(nodo->hijoder, tope, cont);
    }

    if(cont >= tope){
        return;
    }

    nodo->clave->escribir();
    cont++;
    
    if(nodo->hijoizq != nullptr){
        last(nodo->hijoizq, tope, cont);
    }
    
    return;
}



int ArbolAVL::date(Nodo *nodo, Fecha fearly, Fecha flate, int &contador){
    //es_mayor = ha ocurrido antes que; es_menor: ha ocurrido despues de.
    if(nodo == nullptr){
        return;
    }

    Fecha actual = nodo->clave->devolver_fecha();
    
    //Tengo nodo derecho
    if(nodo->hijoder != nullptr && actual.es_menor(fearly)){
        date(nodo->hijoder, fearly, flate, contador);
    }
    
    //Estoy en el rango?
    if((actual.es_menor(fearly) || actual.es_igual(fearly)) && (actual.es_mayor(flate) || actual.es_igual(flate))){   //f1 <= actual <= f2
        contador++;                                         //f1 == actual <= f2 si se supone que f1 > f2 ò f1== f2
        cout<<contador<<". ";
        nodo->clave->escribir();
    }
    
    if(nodo->hijoizq != nullptr && actual.es_mayor(fearly)){
        date(nodo->hijoizq, fearly, flate, contador);
    } 
    return contador;
}



/*
int LAST(tope, contador = 0) <-- tiene que buscar los nodos.
    //quizá meter un contador para saber cuántas veces tenemos que imprimir nodos estaría bien. Last n nos lo da. De un while
    
    si cont >= tope
        return contador         

    Si tiene Derecha -> der.last()
       (Vuelve de la derecha)
    
    IMPRIME EL NODO ACTUAL (Sin preguntar nada más)
    cont++

    Si tiene Izquierda -> Ve a la Izquierda
    (Vuelve de la Izquierda)
    return contador
    
    
*/

/*
    nodo.date(fmin, fmax){

    //Caso1: actual.fecha es menor 
    Si (hijoder) Y (nodo->fecha < F_max) -> hijoder.date(F_min, F_max)

    //Caso2: actual.fecha está entre fmin y fmax
    Si (nodo->fecha >= F_min) Y (nodo->fecha <= F_max) -> nodo.imprime()

    //Caso3: tengo que comprobar la izquierda, sii mi fecha es mayor que fmin
    Si (hijoizq) Y (nodo->fecha > F_min) -> hijoizq.date(F_min, F_max)

    return

    }
*/