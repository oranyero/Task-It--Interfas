//
//  tfecha.cpp
//  Proyecto PEL
//
//  Created by Manuel Lima Velázquez on 10/06/13.
//  Copyright (c) 2013 Oranyero España. All rights reserved.
//

#include "tfecha.h"


//Compara dos fechas para ordenador ordenado
/*
 Funcion comparar:
 Devuelve 0 si son iguales
 Devuelve 1 si la primera fecha es mayor que la segunda
 Devuelve -1 si la primera fecha es menor que la segunda.
 */

int compararFechas(tfecha fecha1, tfecha fecha2) {
    
    if(fecha1.anio == fecha2.anio) { //si el año de las dos fechas es igual, se comparan primero los meses
        
        if(fecha1.mes == fecha2.mes) { //si el primer mes es igual que el segundo, se pasa a comparar los días
            
            if (fecha1.dia == fecha2.dia) { //si el primer día es igual que el segundo, se devuelve 0
                
                return 0;
            }
            
            else if (fecha1.dia < fecha2.dia) { //si el primer día es menor que el segundo, se devuelve -1
                
                return -1;
            }
            
            else { //si el primer día es mayor que el segundo, se devuelve 1
                
                return 1;
            }
        }
        
        else if (fecha1.mes<fecha2.mes) { //si el primer mes es menor que el segundo, se devuelve -1
            
            return -1;
        }
        
        else { //si el primer mes es mayor que el segundo, se devuelve 1
            
            return 1;
        }
    }
    
    else if (fecha1.anio<fecha2.anio) { //si el primer año es menor que el otro, se devuelve -1
        
        return -1;
    }
    
    else { //si el primer año es mayor que el otro, se devuelve 1
        
        return 1;
    }
}

int leerMes(){
    
    int datoSalida;

    do{
        cin>>datoSalida;
        
        if (datoSalida<0 || datoSalida>12){
            cout<<"\nError, introduzca un dato entre 1 y 12: "<<endl;
            cout<<"\nVuelva a escribirlo: ";
        }
        
    } while (datoSalida <0 || datoSalida>12);
    
    return datoSalida;
}

bool esBisiesto(int anio){
    
    bool esBisiesto;
    
    if ( anio%4==0 ){
        
        esBisiesto = true;
        
        if (anio%100==0 && anio%400!=0 ){
            esBisiesto = false;
        }
        
    } else {
        esBisiesto = false;
    }
    
    return(esBisiesto);
    
}

thora leerHora(){
    thora hora;

    cout<<"Hora: ";
    hora.hora = leerNhoras();
    
    cout<<" Minuto: ";
    hora.minuto = leerNminutos();
    
    return (hora);
}

int leerNhoras(){
    int num;

    do{
        cin>> num;
        
        if (num<0 || num>24){
            cout << "\nERROR. Escribe una hora entre 0 y 24"<<endl;
            cout << "\nVuelva a escribirlo: ";
        }
        
    } while (num < 0 || num > 24);
    
    return (num);
}

int leerNminutos(){
    
    int num;
    
    do{
        
        cin>> num;
        
        if (num < 0 || num > 59){
            
            cout << "\nERROR. Escribe los minutos de un valor entre 0 y 59." << endl;
            cout << "\nVuelva a escribirlo: ";
        }
    }while (num < 0 || num > 59);
    
    return (num);
}

tfecha leerFecha(){

    tfecha fecha;
    bool diaIncorrecto, Bisiesto;
    
    cout << "\nAnio: ";
    cin >> fecha.anio;
    Bisiesto = esBisiesto(fecha.anio);
    cout << "\nMes: ";
    
    fecha.mes = leerMes();
    
    do{
        
        cout<<" Dia: ";
        cin>>fecha.dia;
        
        switch (fecha.mes){
                
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                
                if (fecha.dia>31){
                    diaIncorrecto = true;
                } else {
                    diaIncorrecto = false;
                }
                break;
                
            case 2:
                if (Bisiesto==true){
                    
                    if (fecha.dia>29){
                        diaIncorrecto = true;
                    } else {
                        diaIncorrecto = false;
                    }
                }
                if (Bisiesto == false){
                    
                    if (fecha.dia > 28){
                        diaIncorrecto = true;
                    } else {
                        diaIncorrecto = false;
                    }
                }
                break;
                
            default :
                
                if (fecha.dia>30){
                    diaIncorrecto = true;
                } else {
                    diaIncorrecto = false;
                }
        }
        
        if (diaIncorrecto == true){
            cout << "\nError, dia no valido para ese mes. Dia:";
            cout << "\nVuelva a escribirlo: ";
        }
        
    }while (diaIncorrecto);
    
    return (fecha);
}
