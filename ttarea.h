#ifndef ttarea_H
#define ttarea_H

#include "iostream"
#include "tfecha.h"
using namespace std;

//tipos

struct ttarea{
    tfecha fecha;
    thora hora;
    char descripcion[50];
    int prioritario;
    int eliminar;
};

/*
 LA FUNCIÓN COMPARAR NOS VA A DEVOLVER UN TRUE SI SON IGUALES
 bool comparar (ttarea, ttarea);
 */

int comparar(ttarea,ttarea);

/**********************************************************************************
 
 FUnción mia de comparar para el insertar ordenado
 
 int comparar (ttarea,ttarea)
 si es igual devuelve 0
 si es mayor la primera tarea que se compara que la segunda se devuelve 1
 si es menor la primera tarea que se compara que la segunda se devuelve 2
 
 
 **********************************************************************************/

/*
 
 La funcion escribir escribe un ttarea
 
 */

void escribir(ttarea);
void modificarTarea(ttarea &);
void leerTarea(ttarea &);

#endif // PROGRAMA_H
