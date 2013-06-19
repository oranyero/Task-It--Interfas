
#include "ttarea.h"

void leerTarea(ttarea &nuevaTarea){
    
    cout<<"Introduzca la fecha: "<<endl;
    nuevaTarea.fecha = leerFecha();
    
    cout<<"Introduzca la hora de la tarea: "<<endl;
    nuevaTarea.hora = leerHora();
    
    cin.ignore ( 80, '\n' );
    
    cout<<"Introduzca la descripcion de la tarea: ";
    cin.getline(nuevaTarea.descripcion, 150, '\n');
    
    cout<<"Prioridad de la tarea, (1. Baja, 2. Media, 3. Alta): ";
    nuevaTarea.prioritario = validarPrioridad();
    
}


int comparar(ttarea a, ttarea b){
    
    if (compararFechas(a.fecha, b.fecha) == 0)
    return 0;
        
    else if (compararFechas(a.fecha, b.fecha) == 1)
    return 1;
            
    else
    return 2;
    
}

void modificarTarea(ttarea &m){
        
    leerTarea(m);
    
}

void escribir(ttarea e){

cout << "Nevo dia: " << e.fecha.dia << endl;

cout << "Nuevo mes: " << e.fecha.mes << endl;

cout << "Nuevo año: " << e.fecha.anio << endl;

cout << "Nueva hora: " << e.hora.hora << endl;

cout << "Nuevo minuto: " << e.hora.minuto << endl;

cout << "Nueva descripción: " << e.descripcion << endl;

cout << "Nueva prioridad: " << e.prioritario << endl;
    
}

int validarPrioridad(){
    //esta funcion valida que la prioridad sea un valor comprendido entre 1 y 3
    int datoSalida;
    do{
        cin>>datoSalida;
        if (datoSalida<=0||datoSalida>3){
            cout<<"Error, introduzca una prioridad valida ";
        }
    } while (datoSalida <=0|| datoSalida>3);
    return datoSalida;
}

float leerRealPositivo(){
    //esta funcion no se utiliza en el programa pero permanece por si es necesaria su utilizacion
    float datoSalida;
    do{
        cin>>datoSalida;
        if (datoSalida<=0){
            cout<<"Error, introduzca un dato mayor que 0: ";
        }
    } while (datoSalida <=0);
    return datoSalida;
}
