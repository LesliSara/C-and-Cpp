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

void inicializar(float datos[], int n){
    for(int i=0; i<n; i++)
        datos[i]=0;
}

void cambiar_n(int *n, int nuevo){
    *n=nuevo; //como no retorna, entonces así solo cambiará el tamaño
}

void llenar(float datos[], int n){
	for(int i=0; i<n; i++){
        printf("Ingrese el numero [%d]: ", i+1);
        scanf("%f", &datos[i]);
    }
}


void imprimir(float datos[], int n){
    for(int i=0; i<n; i++){
        printf("Dato [%d]: %.4f\n ", i+1, datos[i]);
    }
}

//ordenamiento bubble sort en caso de ser necesario
void bubbleSort(float datos[], int n){
    int i, j, exchange;
    for(i=n-1; i>0; i--){
        exchange = 0; //variable booleana para detener codigo en caso de que ya este ordenado
        for(j=0; j<i; j++){
            if(datos[j]>datos[j+1]){
                float aux = datos[j];
                datos[j] = datos[j+1];
                datos[j+1] = aux;
                exchange = 1;
            }
        }
        if (!exchange)
            break;
    }
}


float media(float datos[], int n){
    float media=0;
    for(int i=0; i<n; i++)
        media+=datos[i];
    media=media/n;
	return media;
}

float mediana(float datos[], int n){
    bubbleSort(datos, n);
    float mediana=0;
	if (n%2==0)
        mediana=(datos[n/2]+datos[n/2-1])/2;
    else
        mediana=datos[n/2-1]/2;
    return mediana;
}


float moda(float datos[], int n){
    float moda=datos[0];
    int modaMax=1;//Max de repeticiones, inica en 1 porque todos al menos están 1 vez
	for(int i=0; i<n; i++){
        int repeticiones=0;
        for(int j=0; j<n; j++){
            if(datos[i]==datos[j])
                repeticiones++; 
        }
        if(repeticiones>modaMax){
            modaMax=repeticiones;
            moda=datos[i];
        }
        if (modaMax==1)
            return -1;
        else
            return moda;
        
    }
}

float rango(float datos[], int n){
    float rango =datos[n-1]-datos[0];
	return rango;
}

float varianza(float datos[], int n){
    float sumatoria=0, varianza;
    for (int i=0; i<n; i++){
        sumatoria+=(float)pow(datos[i]-media(datos, n),2);
    }
    varianza=sumatoria/(n-1);
	return varianza;
}

float des_estandar(float datos[], int n){
    float desviacion=(float)sqrt(varianza(datos, n));
	return desviacion;
}

float cuartil_1(float datos[], int n){
    bubbleSort(datos, n);
    float posicion, cuartil1;
    if (n%2==0)
        posicion=n/4;
    else
        posicion=(n+1)/4;
    if ((int)posicion%2==0)
        cuartil1=datos[(int)posicion-1];
    else
        cuartil1=(datos[(int)posicion]+datos[(int)posicion-1])/2;
	return cuartil1;	
}

float cuartil_3(float datos[], int n){
	bubbleSort(datos, n);
    float posicion, cuartil3;
    if (n%2==0)
        posicion=3*n/4;
    else
        posicion=3*(n+1)/4;
    if ((int)posicion%2==0)
        cuartil3=datos[(int)posicion-1];
    else
        cuartil3=(datos[(int)posicion]+datos[(int)posicion-1])/2;
	return cuartil3;
}

float rango_intercuartil(float datos[], int n){
    float ric= cuartil_3(datos, n) - cuartil_1(datos, n);
	return ric;
}

void todo(float datos[], int n){
    printf(" MEDIDAS DE TENDENCIA CENTRAL Y DE DISPERSION\n");
    printf("|--------------------------------------------|\n");
    printf("| Media               |%22.4f|\n", media(datos, n));
    printf("| Mediana             |%22.4f|\n", mediana(datos, n));
    printf("| Moda                |%22.4f|\n", moda(datos, n));
    printf("| Varianza            |%22.4f|\n", varianza(datos, n));
    printf("| Desviacion estandar |%22.4f|\n", des_estandar(datos, n));
    printf("| Cuartil 1           |%22.4f|\n", cuartil_1(datos, n));
    printf("| Cuartil 3           |%22.4f|\n", cuartil_3(datos, n));
    printf("| Rango intercuartil  |%22.4f|\n", rango_intercuartil(datos, n));
    printf("| Rango               |%22.4f|\n", rango(datos, n));
    printf("----------------------------------------------\n");
}
