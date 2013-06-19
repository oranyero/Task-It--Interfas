#ifndef tlista_H
#define tlista_H

#include <iostream>
#include <fstream>
using namespace std;

#include "ttarea.h"

typedef ttarea telemento;

struct tnodo{

    telemento elemento;
    tnodo * sig;

};

typedef tnodo * tlista; //esto quiere decir que tlista es un puntero a tnodo
typedef tnodo * tposicion;   

bool esVacia (tlista);
void insertarPrincipio (tlista &,telemento);
void insertarFinal(tlista &, telemento);
void insertarOrdenado(tlista &, telemento);
void borrar (tlista &,tposicion);
void mostrarLista(tlista);
int longitud(tlista);
tposicion buscarPosicion (tlista,telemento);
bool modificarLista(tlista &,telemento);

bool leerNhoras(int &);

#endif // PROGRAMA_H
