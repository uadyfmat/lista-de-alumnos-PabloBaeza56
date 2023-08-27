#include <stdio.h>
#include <stdlib.h>


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
typedef Alumno* AlumnoPtr;
//crear alumno
// crear nodo 
// insertar nodo ordenado creditos
// imprimir lista 

//*Alumno crearAlumno(*char, int, int); ok
//void imprimirLista();
// *Nodo crearNodo(*Alumno)
//int insertarNodoOrdenadoCreditos(*nodo);
//void imprimirLista();


AlumnoPtr crearAlumno(char* nombreCompleto, int creditosAprobados, int semestreEquivalente);
void imprimirAlumno(NodoPtr actualPtr);

NodoPtr crearNodo(AlumnoPtr alum);
int insertaOrdenado_matricula(NodoPtr *cabecera, NodoPtr nuevoPtr);
void imprimeLista(NodoPtr actualPtr);





int main(int argc, char const *argv[]){
   
    NodoPtr cabecera = NULL;

    AlumnoPtr primer_alumno = crearAlumno("Baeza Lara Pablo Ernesto", 56, 8);
    AlumnoPtr segundo_alumno = crearAlumno("Arana Cetina Jesus Armando", 30, 6);
    AlumnoPtr tercer_alumno = crearAlumno("Carbajal Perza Efren Arjona", 8, 5);
    AlumnoPtr cuarto_alumno = crearAlumno("Andre Joaquin Burgos", 3, 2);
    AlumnoPtr quinto_alumno = crearAlumno("Ayuso Sebastian Camilo", 10, 1);

    
    imprimirDireccionEstructura(primer_alumno);
    imprimirDireccionEstructura(segundo_alumno);
    imprimirDireccionEstructura(tercer_alumno);
    imprimirDireccionEstructura(cuarto_alumno);
    imprimirDireccionEstructura(quinto_alumno);
    printf("\n");

    NodoPtr primer_nodo = crearNodo(primer_alumno);
    NodoPtr segundo_nodo = crearNodo(segundo_alumno);
    NodoPtr tercer_nodo = crearNodo(tercer_alumno);
    NodoPtr cuarto_nodo = crearNodo(cuarto_alumno);
    NodoPtr quinto_nodo = crearNodo(quinto_alumno);
    
    
    imprimirDireccionNodo(primer_nodo);
    imprimirDireccionNodo(segundo_nodo);
    imprimirDireccionNodo(tercer_nodo);
    imprimirDireccionNodo(cuarto_nodo);
    imprimirDireccionNodo(quinto_nodo);
    
    
    insertaOrdenado_matricula(&cabecera, primer_nodo);
    insertaOrdenado_matricula(&cabecera, segundo_nodo);
    insertaOrdenado_matricula(&cabecera, tercer_nodo);
    insertaOrdenado_matricula(&cabecera, cuarto_nodo);
    insertaOrdenado_matricula(&cabecera, quinto_nodo);
    
    imprimeLista(cabecera);
    
    
    return 0;
}

void imprimirDireccionEstructura(AlumnoPtr alum){
    printf("Se ha creado una estructura Alumno en la direccion: %p \n", alum);
}

void imprimirDireccionNodo(NodoPtr nodo){
    printf("Se ha creado un nodo en la lista de Alumnos en: %p \n", nodo);
}


AlumnoPtr crearAlumno(char* nombreCompleto, int creditosAprobados, int semestreEquivalente){
    AlumnoPtr alum = (AlumnoPtr)malloc(sizeof(Alumno));
    
    alum->nombreCompleto = nombreCompleto;
    alum->creditosAprobados = creditosAprobados;
    alum->semestreEquivalente = semestreEquivalente;
    return alum;
}




NodoPtr crearNodo(AlumnoPtr alum){
	NodoPtr nuevoNodo = (Nodo *)malloc(sizeof(Nodo));

    nuevoNodo->Alumno.nombreCompleto = alum.nombreCompleto;
	nuevoNodo->Alumno.creditosAprobados = alum.creditosAprobados;
    nuevoNodo->Alumno.semestreEquivalente = alum.semestreEquivalente;
	nuevoNodo->siguientePtr = NULL;

	return nuevoNodo;
}


int insertaOrdenado_matricula(NodoPtr *cabecera, NodoPtr nuevoPtr){
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
    return 0;
}

void imprimeLista(NodoPtr actualPtr){
    if (actualPtr == NULL) {
        printf("Lista vacia \n");
    } else {
        printf("\n");
        printf("Impresion de la lista Alumnos (Creditos Ascendentes): \n");

        while (actualPtr != NULL){
            printf("Nombre: %s , Creditos aprobados:%d , Semestre equivalente:%d   \n", actualPtr->Alumno.nombreCompleto,actualPtr->Alumno.creditosAprobados, actualPtr->Alumno.semestreEquivalente);
            actualPtr = actualPtr->siguientePtr;
        }
        
    }
}

void imprimirAlumno(NodoPtr actualPtr){
    printf("Datos especificos del alumno: \n");
    printf("Nombre: %s ,Creditos aprobados: %d , Semestre equivalente: %d   \n",
    actualPtr->Alumno.nombreCompleto,
    actualPtr->Alumno.creditosAprobados,
    actualPtr->Alumno.semestreEquivalente);
};

void liberarMemoria(NodoPtr actualPtr){
    while (actualPtr != NULL){
        free(actualPtr); 
        actualPtr = actualPtr->siguientePtr;
    }
}




