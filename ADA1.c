#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno{
    char* nombreCompleto;
    int creditosAprobados;
    int semestreEquivalente;
}Alumno;

typedef struct nodo{
    struct alumno Alumno;
    struct nodo *siguientePtr;
}Nodo;

typedef Nodo* NodoPtr;

Alumno leer_Datos(char* nombreCompleto, int creditosAprobados, int semestreEquivalente);
NodoPtr crearNodo(Alumno alum);
void insertaOrdenado_matricula(NodoPtr *cabecera, NodoPtr nuevoPtr);
void imprimeLista(NodoPtr actualPtr);


int main(int argc, char const *argv[]){
   
    NodoPtr cabecera = NULL;

    Alumno primer_alumno = leer_Datos("Baeza Lara Pablo Ernesto", 56, 8);
    Alumno segundo_alumno = leer_Datos("Arana Cetina Jesus Armando", 30, 6);
    Alumno tercer_alumno = leer_Datos("Carbajal Perza Efren Arjona", 8, 5);
    Alumno cuarto_alumno = leer_Datos("Andre Joaquin Burgos", 3, 2);
    Alumno quinto_alumno = leer_Datos("Ayuso Sebastian Camilo", 10, 1);


    NodoPtr primer_nodo = crearNodo(primer_alumno);
    NodoPtr segundo_nodo = crearNodo(segundo_alumno);
    NodoPtr tercer_nodo = crearNodo(tercer_alumno);
    NodoPtr cuarto_nodo = crearNodo(cuarto_alumno);
    NodoPtr quinto_nodo = crearNodo(quinto_alumno);
    
    insertaOrdenado_matricula(&cabecera, primer_nodo);
    insertaOrdenado_matricula(&cabecera, segundo_nodo);
    insertaOrdenado_matricula(&cabecera, tercer_nodo);
    insertaOrdenado_matricula(&cabecera, cuarto_nodo);
    insertaOrdenado_matricula(&cabecera, quinto_nodo);
    
    imprimeLista(cabecera);
    return 0;
}


Alumno leer_Datos(char* nombreCompleto, int creditosAprobados, int semestreEquivalente){
    Alumno alum;
    alum.nombreCompleto = nombreCompleto;
    alum.creditosAprobados = creditosAprobados;
    alum.semestreEquivalente = semestreEquivalente;
    return alum;
}


NodoPtr crearNodo(Alumno alum){
	NodoPtr nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    	nuevoNodo->Alumno.nombreCompleto = alum.nombreCompleto;
	nuevoNodo->Alumno.creditosAprobados = alum.creditosAprobados;
    	nuevoNodo->Alumno.semestreEquivalente = alum.semestreEquivalente;
	nuevoNodo->siguientePtr = NULL;

	return nuevoNodo;
}



void insertaOrdenado_matricula(NodoPtr *cabecera, NodoPtr nuevoPtr){
    NodoPtr actualPtr = *cabecera;
    NodoPtr anteriorPtr = NULL;
    
    if (nuevoPtr != NULL){
        // Recorrer la lista ligada, agregar los valores ordenadamente, AQUI SE GENERA LA COMPRARACION
        while (actualPtr != NULL && nuevoPtr->Alumno.creditosAprobados < actualPtr->Alumno.creditosAprobados){
            anteriorPtr = actualPtr;
            actualPtr = actualPtr->siguientePtr;
        }

        if (anteriorPtr == NULL){
            nuevoPtr->siguientePtr = *cabecera;
            *cabecera = nuevoPtr;
        }else{

           anteriorPtr->siguientePtr = nuevoPtr;
           nuevoPtr->siguientePtr = actualPtr;
 
        }
    }else{
        puts("No hay memoria disponible");
    }
}




void imprimeLista(NodoPtr actualPtr){
    if (actualPtr == NULL) {
        printf("Lista vacia \n");
    } else {
        printf("\n");
        printf("Contenido de la lista: \n");

        while (actualPtr != NULL){
            printf("Nombre: %s ,Creditos aprobados:%d , Semestre equivalente:%d   \n", actualPtr->Alumno.nombreCompleto,actualPtr->Alumno.creditosAprobados, actualPtr->Alumno.semestreEquivalente);
            actualPtr = actualPtr->siguientePtr;
        }
        
    }
}




