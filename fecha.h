#ifndef tfecha_H
#define tfecha_H

#include <iostream>
using namespace std;

//tipos

struct tfecha{
    int dia;
    int mes;
    int anio;
};

struct thora{
    int hora;
    int minuto;
};

int compararFechas(tfecha, tfecha);
int leerMes();
bool esBisiesto(int);
thora leerHora();
int leerNhoras();
int leerNminutos();
tfecha leerFecha();
int validarPrioridad();
float leerRealPositivo();

#endif // PROGRAMA_H
