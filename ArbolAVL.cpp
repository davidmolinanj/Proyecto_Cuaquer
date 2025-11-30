#include "Nodo.h"
#include "ArbolAVL.h"
#include <math.h>
using namespace std;



//#TODO: habrá que hacer que cuando se crear un nodo en la tabla hash, el nodo apunte a la dirección de la 
//tabla hash y se cree así el árbol
 
//TODO: Hay que hacer un getAltura xq sino el código cuando el nodo no tiene hijos peta (chati)
//HOLA HOLA PROBANDO PROBANDO

void ArbolAVL::RSI(Nodo *&nodo){
    Nodo *nodoB = nodo->hijoizq;
    nodo->hijoizq = nodoB->hijoder;
    nodoB->hijoder = nodo;
    nodo->altura = 1 + max((nodo->hijoizq->altura),(nodo->hijoder->altura));
    nodoB->altura = 1 + max((nodoB->hijoizq->altura),(nodo->altura));
    nodo = nodoB;
}

//aplico RSD(A)
void ArbolAVL::RSD(Nodo *&nodo){ //nodo = A y nodo->hijoder = B
    Nodo *nodoB = nodo->hijoder;
    nodo->hijoder = nodoB->hijoizq;
    nodoB->hijoizq = nodo;
    nodo->altura = 1 + max((nodo->hijoizq->altura),(nodo->hijoder->altura));
    nodoB->altura = 1 + max((nodoB->hijoizq->altura),(nodo->altura));
    nodo = nodoB;
}

int ArbolAVL::balance(Nodo *nodo){  //no entiendo muy bien que hace ni para que queremos esto
    return (abs(nodo->hijoder->altura + nodo->hijoizq->altura));
}

void ArbolAVL::comprobarGiroMagistral(Nodo *nodo){
    //altura inicia en -1, para ir mirando los niveles y eso.
    if(balance(nodo) > 1 && balance(nodo->hijoizq) >= 0){
        RSI(nodo);
    }
    if(balance(nodo) > 1 && balance(nodo->hijoizq) < 0){
        RDI(nodo);
    }
    if(balance(nodo) < -1 && balance(nodo->hijoizq) > 0){
        RDD(nodo);
    }
    if(balance(nodo) < -1 && balance(nodo->hijoizq) <= 0){
        RSD(nodo);
    }
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