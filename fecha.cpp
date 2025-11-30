#include "fecha.h"
#include <iostream>
#include <string>

using namespace std;


// DD/MM/AAAA HH:MM:SS
void Fecha::setFecha(){
    char separador; //para coger los '/' y  los ':'
    cin >> dia >> separador >> mes >> separador >> ano;
    cin >> horas >> separador >> minutos >> separador >> segundos;
    cin.ignore();
}


bool Fecha::es_igual(Fecha f){
    if(ano == f.ano){
        if(mes == f.mes){
            if(dia==f.dia){
                if(horas==f.horas){
                    if(minutos==f.minutos){
                        if(segundos==f.segundos){
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool Fecha::es_menor(Fecha f){
    if (ano != f.ano) return ano < f.ano;
    if (mes != f.mes) return mes < f.mes;
    if (dia != f.dia) return dia < f.dia;
    if (horas != f.horas) return horas < f.horas;
    if (minutos != f.minutos) return minutos < f.minutos;
    return segundos < f.segundos;
}

bool Fecha::es_mayor(Fecha f){
    if (es_menor(f) == false && es_igual(f) == false){
        return true;
    }
    return false;
}

void Fecha::mostrar(){
    cout << dia << '/' << mes << '/' << ano << ' ';
    if(horas < 10){
    cout << '0'; 
    }
    cout << horas << ':';

    if(minutos < 10){
    cout << '0'; 
    }
    cout << minutos << ':';

    if(segundos < 10){
    cout << '0';
    }
    cout << segundos; 
}