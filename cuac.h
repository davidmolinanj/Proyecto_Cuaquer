#ifndef CUAC_H
#define CUAC_H
#include <string>
#include "fecha.h"
using namespace std;

#define NUMERO_MENSAJES 30

class Cuac {

  friend class DiccionarioCuacs;
  friend class TablaHash;

  private:
    Fecha fecha;
    string nombre;
    string texto;
    //char texto[141];
    
  public:
    bool procesar_mcuac();        //lee un cuac de la entrada estándar
    bool procesar_pcuac();        //lee un cuac de la entrada estándar (para pcuac)
    void escribir();              //escribe un cuac en la salida estándar
    Fecha devolver_fecha();       //devuelve la fecha del cuac
    bool es_anterior(Cuac &otro); //devuelve true si el cuac actual es anterior a otro
};

//pongo un comentario pq estoy probando a actualizar todos los ficheros

#endif
