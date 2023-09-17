#include "operaciones.h"
#include <stdio.h>
#include <math.h>

void ver_comandos(){
    printf("-----------CALCULADORA DE MEDIDAS Y TENDENCIA CENTRAL Y DE DISPERSION------------\n");
    printf("INSTRUCCIONES: Cuando aparezca '>', puedes teclear cualquiera de los siguientes comandos que se muestran en la siguiente tabla\n");
    printf("-----------------------------------------------------------------------------\n");
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
    printf("-----------------------------------------------------------------------------\n");
}

//La función inicializa el arreglo de tamaño 100 con 0 en todas sus posiciones
void inicializar(float datos[], int n){
    for(int i=0; i<n; i++)
        datos[i]=0;
}

//cambia el tamaño del arreglo
void cambiar_n(int *n, int nuevo){
    *n=nuevo; //como no retorna, entonces así solo cambiará el tamaño
}

//Funcion que llena el arreglo desde la posicion 0 hasta el tamaño dado por el usuario o el default
void llenar(float datos[], int n){
	for(int i=0; i<n; i++){
        printf("Ingrese el numero [%d]: ", i+1);
        scanf("%f", &datos[i]);
    }
}

//Imprime el arreglo sin ordenar
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

//Obtiene el promedio del arreglo
float media(float datos[], int n){
    float media=0;
    for(int i=0; i<n; i++)
        media+=datos[i];
    media=media/n;
	return media;
}

//Para obtener la mediana primero los ordena y luego lo obtiene
//En caso de que sea par la cantidad de datos, se van a sumar el de la posicion x más uno de la posicion-1
//En caso de que sea impar, simplemente retorna el valor en medio de los datos
float mediana(float datos[], int n){
    bubbleSort(datos, n);
    float mediana=0;
	if (n%2==0)
        mediana=(datos[n/2]+datos[n/2-1])/2;
    else
        mediana=datos[(n+1)/2-1];
    return mediana;
}

//Funcion unimodal, solo va a mostrar una moda
//En caso de que se repita la misma cantidad por número, tomará en cuenta como la moda el primer valor
//Si todos los datos se encuentran solo 1 vez en el arreglo, entonces retornará un -1
float moda(float datos[], int n){
    float moda=datos[0];
    int modaMax=1;//Max de repeticiones, inica en 1 porque todos al menos están 1 vez
	for(int i=0; i<n; i++){
        int repeticiones=0;
        for(int j=0; j<n; j++){
            if(datos[i]==datos[j]){
                repeticiones++; 
            }
        }
        if(repeticiones>modaMax){
            modaMax=repeticiones;
            moda=datos[i];
        }  
    }
    if (modaMax==1)
        return -1;
    else
        return moda;
}

//Para saber su rango, se ordena y se resta el mayor menos el menor
float rango(float datos[], int n){
    bubbleSort(datos, n);
    float rango =datos[n-1]-datos[0];
	return rango;
}

//Funcion para obtener la varianza, no es necesario el ordenamiento, en este caso se necesita de la funcion media
float varianza(float datos[], int n){
    float sumatoria=0, varianza;
    for (int i=0; i<n; i++){
        sumatoria+=(float)pow(datos[i]-media(datos, n),2);
    }
    varianza=sumatoria/(n-1);
	return varianza;
}

//Para la desviación estándar ocupamos lo que retorna la funcion varinza y se le saca la raiz cuadrada
float des_estandar(float datos[], int n){
    float desviacion=(float)sqrt(varianza(datos, n));
	return desviacion;
}

/*Esto aplica tanto para el cuartil 1 como 2. Si la cantidad de datos es par, se va a multiplicar la cantidad de datos
por la del cuartil, es decir si es el cuartil uno, se multiplica por 1, si es el cuartil 3, por 3. Después se divide 
entre 4 y así se obtiene la posición. En caso de que sea impar la cantidad de datos, se le suma 1 al numero de datos
y se multiplica por el cuartil y también se divide entre 4. Finalmente para saber el cuartil se verifica si la posición
es entera o decimal, si es entera, entonces el cuartil es el que valor que hay en esa posicion, si es decimal, se suman
los valores en la posición en el entero anterior y poterior y se divide entre dos*/
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

//Para el rango intercuartil, solo es restar el cuartil 3 con el cuartil uno, entonces usamos los valores que retornan
//las dos funciones anteriores
float rango_intercuartil(float datos[], int n){
    float ric= cuartil_3(datos, n) - cuartil_1(datos, n);
	return ric;
}

//Aqui para mostrar todo, se hace uso de los valores que retorna cada funcion y se muestran en pantalla.
void todo(float datos[], int n){
    printf("Media:               %10.4f\n", media(datos, n));
    printf("Mediana:             %10.4f\n", mediana(datos, n));
    printf("Moda:                %10.4f\n", moda(datos, n));
    printf("Varianza:            %10.4f\n", varianza(datos, n));
    printf("Desviacion estandar: %10.4f\n", des_estandar(datos, n));
    printf("Cuartil 1:           %10.4f\n", cuartil_1(datos, n));
    printf("Cuartil 3:           %10.4f\n", cuartil_3(datos, n));
    printf("Rango intercuartil:  %10.4f\n", rango_intercuartil(datos, n));
    printf("Rango:               %10.4f\n", rango(datos, n));
}
