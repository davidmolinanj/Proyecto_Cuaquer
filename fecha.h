#ifndef FECHA_H
#define FECHA_H

class Fecha{

    friend class DiccionarioCuacs;

    private:    
    int dia, mes, ano;
    int segundos, minutos, horas;

    public:
    Fecha() {
    }

// DD/MM/AAAA HH:MM:SS
void setFecha(); //lee la fecha del formato indicado
bool es_igual(Fecha f); //devuelve true si las fechas son iguales
bool es_menor(Fecha f); //devuelve true si la fecha actual es menor que f
bool es_mayor(Fecha f); //devuelve true si la fecha actual es mayor que f
void mostrar();         //muestra la fecha en el formato indicado
};

//pongo un comentario pq estoy probando a actualizar todos los ficheros
#endif
