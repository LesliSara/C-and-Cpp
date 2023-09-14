#include "operaciones.h"
#include <stdio.h>
#include <math.h>

void ver_comandos(){
    printf("-----------CALCULADORA DE MEDIDAS Y TENDENCIA CENTRAL Y DE DISPERSION------------\n");
    printf("INSTRUCCIONES: Cuando aparezca '>', puedes teclear cualquiera de los siguientes comandos que se muestran en la siguiente tabla\n");
    printf("| COMANDO | FUNCION                                                         |\n");
    printf("|---------------------------------------------------------------------------|\n");
    printf("|  ayuda  | Imprime nuevamente la tabla de ayuda.                           |\n");
    printf("|  salir  | Termina el programa.                                            |\n");
    printf("|    n    | Cambiar la cantidad de datos (por defecto, n=100).              |\n");
    printf("|  datos  | Cambiar todos los datos con los que usted desea trabajar.       |\n");
    printf("| cambiar | Cambiar un dato en la posicion especifica.                      |\n");
    printf("| imprimir| Imprimir los datos ordenados con los que se trabaja actualmente.|\n");
    printf("|  media  | Calcular la media aritmetica del conjunto de datos.             |\n");
    printf("| mediana | Calcular la mediana del conjunto de datos.                      |\n");
    printf("|  moda   | Calcular la moda del conjunto de datos.                         |\n");
    printf("| varianza| Calcular la varianza del conjunto de datos.                     |\n");
    printf("| desvest | Calcular la desviacion estandar del conjunto de datos.          |\n");
    printf("|cuartil_1| Calcular el primer cuartil del conjunto de datos.               |\n");
    printf("|cuartil_3| Calcular el tercer cuartil del conjunto de datos.               |\n");
    printf("|   ric   | Calcular el rango intercuartilico del conjunto de datos.        |\n");
    printf("|  rango  | Calcular el rango del conjunto de datos.                        |\n");
    printf("|  todos  | Calcular todas las medidas del conjunto de datos.               |\n");
}



void llenar(float datos[], int n){
	for(int i=0; i<n; i++){
        printf("Ingrese el numero [%d]: ", i+1);
        scanf("%f", &datos[i]);
    }
}

/*
void imprimir(float datos[], int n){
	
}

float media(float datos[], int n){
	return 0;
}

float mediana(float datos[], int n){
	return 0;
}

float moda(float datos[], int n){
	return 0;
}

float rango(float datos[], int n){
	return 0;
}

float varianza(float datos[], int n){
	return 0;
}

float des_estandar(float datos[], int n){
	return 0;
}

float cuartil_1(float datos[], int n){
	return 0;	
}

float cuartil_3(float datos[], int n){
	return 0;
}

float rango_intercuartil(float datos[], int n){
	return 0;
}

void todo(float datos[], int n){
}*/
