#include "tlista.h"


/*
 
 
                        tnodo              tnodo                tnodo
                    ************       ************         ************
                    * elemento *       * elemento *         * elemento *
        tlista      *          *       *          *         *          *
        [-]-------> ************       ************         ************
                    *          *       *          *         *          *
                    *  sig [-]-*-----> *  sig [-]-*-------> *  sig [X] *
                    ************       ************         ************
 

bool esVacia (tlista);                      //YA
void insertarPrincipio (tlista &,telemento);//YA
void insertarFinal(tlista&, telemento);     //YA
void insertarOrdenado(tlista&, telemento);  
void borrar (tlista &,telemento);           //YA
void mostrar(tlista);                       //YA
int longitudLista(tlista);                  //YA
tposicion buscar (tlista,telemento);        //YA
 
*/


//****************************************************************************

bool esVacia (tlista l){

    return (l == NULL);
}

//****************************************************************************

void insertarPrincipio (tlista &l, telemento e){
    
    tnodo * nuevonodo;
    nuevonodo = new tnodo;
    nuevonodo->elemento = e; //(*nuevonodo).elemento = e;
    nuevonodo->sig = l;
    l=nuevonodo;

}

//****************************************************************************


void insertarFinal(tlista&l,telemento e){

    tnodo * nn;
    nn = new tnodo;
    nn->elemento = e;
    
    tposicion p;
    
    if (esVacia(l)){
    
        nn->sig = NULL;
        l = nn;
        
    }else{
    
        for (p = l; p->sig != NULL; p = p->sig) {
            
        }
        
        p->sig = nn;
        nn->sig = NULL;
    }
    

}


//BUSCAR La HEMOS REALIZADO DIFERENTE DE MACU, VERIFICAR CON ELLA

//****************************************************************************


// TENEMOS QUE TENER YA LOS REQUIITOS FIJOS DE LA FUNCIÓN COMPARAR Y YA DESPUES MODIFIREMOS EL TDA LISTA



tposicion buscarPosicion (tlista l, telemento e){
    
    bool encontrado = false;
    tposicion p;
    p = l;
    
    if (!esVacia(l)){
        
    for (p = l; ((encontrado == false) && (p->sig != NULL)); p = p->sig) {
        
        if (comparar(e, p->elemento) == true){
        
            encontrado = true;
        }
        
    }


}
 
    return p;

}

//*************************************************************************

void borrar (tlista &l, tposicion p){

    
    tposicion pant;
    
    if (p!=l){
    
        for (pant = l; pant->sig != p; pant = pant->sig) {
            
            
        }
        
        pant->sig = p->sig;
    
        
        
    }else{
    
        l = l->sig;
    
    }
    
    delete p;

}

//****************************************************************************

void mostrarLista (tlista l){

    tposicion p;
    
    for (p = l; p != NULL; p = p->sig) {
        
       escribir(p->elemento);
        
    }


}


//****************************************************************************

int longitud(tlista l){

    int contador=0;
    tposicion p;
    
    for (p=l; p!=NULL; p=p->sig) {
        contador++;
    }
    return contador;
}


/**********************************************************************************
 
 Función mia de comparar para el insertar ordenado
 
 int comparar (ttarea,ttarea)
 si es igual devuelve 0
 si es mayor la primera tarea que se compara que la segunda se devuelve 1
 si es menor la primera tarea que se compara que la segunda se devuelve 2
 
 
 **********************************************************************************/



 
 void insertarOrdenado (tlista &l, telemento e){

    tposicion p;
    tposicion pant;
    tnodo *nn;
    nn=new tnodo;
    nn->elemento=e;
    
    if (esVacia(l)){
    
        nn->sig=NULL;
        l=nn;
    
        
    }else{
        
        for (p=l->sig,pant=l; ((p!=NULL)&&(!((comparar(e, pant->elemento)==1)&&(comparar(e, p->elemento)==2)))) ; p=p->sig,pant=pant->sig) {
        
        }
        
        nn->sig=p;
        pant->sig=nn;
        
    
    }
    
    
}



bool modificarLista(tlista &l,telemento e){
    
    tposicion posicion;
    
    if (!esVacia(l)){
        
    posicion = buscarPosicion(l, e);
    
    modificarTarea(posicion->elemento);
        
    return true;
    } else
     return false;
}








