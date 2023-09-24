#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //biblioteca que contiene isalpha
#include <string.h>
#include "contador.h"

Nodo *conjunto;//maximo de 200 palabras en el txt
int totalPalabras=0;

//Recibe una cadena, la convierte toda a minúsculas y le quita puntos (.), comas (,) y letras 's'.
void limpiar_palabra(char* palabra){
    int j=0;
    int s=0; //booleano
    for(int i=0; i<strlen(palabra); i++){
        if (isalpha(palabra[i])){
            palabra[j++]=tolower(palabra[i]);
        } 
        if (i == strlen(palabra) - 1 && palabra[i] == 's' && j > 0) {
            // Si encontramos una 's' al final de la palabra y la palabra no está vacía, la omitimos
            //va a quitar todas las s's finales, sin importar si es plular o no, pero es lo más cercano 
            palabra[--j] = '\0'; // Eliminamos la 's' y agregamos el carácter nulo
        }
    }
    // Agregamos el carácter nulo al final de la cadena resultante
    palabra[j] = '\0';
}

/*Si la palabra está en el conjunto, incrementa su frecuencia. 
Si no, la agrega. En cualquiera de los dos casos, regresa el conjunto actualizado.*/
void contar_palabra(char* palabra, Nodo* conjunto){
    int pos=buscar_palabra(palabra, conjunto);
    printf("pos: %i\n", pos);
    printf("palabras: %i\n", totalPalabras);
    if (pos!=-1){
        conjunto[pos].frecuencia++;//Si se encuentra la palabra en el conjunto, entonces solo aumenta su frecuencia
        printf("%s %i\n", conjunto[pos].palabra, conjunto[pos].frecuencia);
    } else {
        printf("%i\n", totalPalabras);
        //strcpy(conjunto[totalPalabras].palabra, palabra);//En el miembro de palabra se le asigna la palabra nueva a agregar
        //printf("%s\n", conjunto[totalPalabras].palabra);
        conjunto[totalPalabras].frecuencia=1;//como apenas se agrega la palabra, su frecuencia será de 1
        printf("%i\n", conjunto[totalPalabras].frecuencia);
        /*printf("%s %i\n", conjunto[totalPalabras].palabra, conjunto[totalPalabras].frecuencia);
        totalPalabras++;
        printf("%i\n", totalPalabras);*/
    }
    
}

//Si encuentra la palabra en el conjunto, regresa su índice. Si no, regresa -1.
int buscar_palabra(char* palabra, Nodo* conjunto){
    for (int i=0; i<totalPalabras; i++){
        if(!strcmp(conjunto[i].palabra, palabra)){
            return i;
        }
    }
    return -1; //regresa en caso de que no se encuentre
}

//Recibe el arreglo de palabras y lo regresa ordenado de mayor a menor frecuencia.
void ordenar_palabras(Nodo* conjunto){
    Nodo aux;
    for(int i=totalPalabras-1; i>0; i--){
        int exchange = 0; //variable booleana para detener codigo en caso de que ya este ordenado
        for(int j=0; j<i; j++){
            if(conjunto[j].frecuencia > conjunto[j+1].frecuencia){
                aux = conjunto[j];
                conjunto[j] = conjunto[j+1];
                conjunto[j+1] = aux;
                exchange = 1;
            }
        }
        if (!exchange)
            break;
    }
}

//Guarda el arreglo de palabras en un archivo.
void guardar_palabras(Nodo* conjunto, FILE *archivo){
    fprintf(archivo, "|\n\t\tPALABRA\t\t|\t\tFRECUNECIA\t\t|");
    for (int i = 0; i < totalPalabras; i++){
        fprintf(archivo, "|\t\t%s\t\t|\t\t%i\t\t|", conjunto[i].palabra, conjunto[i].frecuencia);
    }
    
}

int main(int argc, char *argv[]) {
    char linea[1024]; // Tamaño máximo de una línea en el archivo
    if (argc != 3) {
        printf("\nUso: %s archivo_entrada.txt archivo_salida.txt\n", argv[0]);
        return 1;
    }

    char *nombreEntrada = argv[1];
    char *nombreSalida = argv[2];

    FILE *archivoEntrada = fopen(nombreEntrada, "r");
    if (archivoEntrada == NULL) {
        printf("Error al abrir el archivo de entrada.\n");
        return 1;
    }


    // Leer el archivo de entrada línea por línea
    while (!feof(archivoEntrada)) {
        while (fgets(linea, sizeof(linea), archivoEntrada)!=NULL)
        {
            char *token = strtok(linea, " \n\t\r");
            while (token != NULL) {
                //printf("%s\n", token);
                limpiar_palabra(token);
                //printf("%s\n", token);
                contar_palabra(token, conjunto); // Contar la palabra y agregarla al conjunto
                printf("%i", totalPalabras);
                token = strtok(NULL, " ");
            }
        }
        
    }
    fclose(archivoEntrada);
    
    
    
    /*
    ordenar_palabras(conjunto);

    for (int i = 0; i < totalPalabras; i++){
        printf("|\t\t%s\t\t|\t\t%i\t\t|", conjunto[i].palabra, conjunto[i].frecuencia);
    }

    //Guardar el conjunto de palabras en el archivo de salida
    FILE *archivo_salida = fopen(nombre_archivo_salida, "w");
    if (archivo_salida != NULL) {
        guardar_palabras(conjunto, archivo_salida);
        fclose(archivo_salida);
    } else {
        printf("Error al abrir el archivo de salida.\n");
        return 1;
    }*/

    return 0;
}
