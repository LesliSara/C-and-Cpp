#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //biblioteca que contiene isalpha
#include <string.h>
#include "contador.h"

Nodo *conjunto;
int totalPalabras=0;

//Recibe una cadena, la convierte toda a minúsculas y le quita puntos (.), comas (,) y letras 's'.
void limpiar_palabra(char* palabra){
    int j=0;
    int s=0; //booleano
    int i;
    for(i=0; i<strlen(palabra); i++){
        if (isalpha(palabra[i])){
            palabra[j++]=tolower(palabra[i]);
        } 
    }
    i=strlen(palabra)-1;
    if (palabra[i] == 's' && j > 0) {
            // Si encontramos una 's' al final de la palabra y la palabra no está vacía, la omitimos
            //va a quitar todas las s's finales, sin importar si es plular o no, pero es lo más cercano 
            palabra[--j] = '\0'; // Eliminamos la 's' y agregamos el carácter nulo
        }
    else palabra[j] = '\0';
}

/*Si la palabra está en el conjunto, incrementa su frecuencia. 
Si no, la agrega. En cualquiera de los dos casos, regresa el conjunto actualizado.*/
void contar_palabra(char* palabra, Nodo* conjunto){
    int pos=buscar_palabra(palabra, conjunto);
    if (pos!=-1){
        conjunto[pos].frecuencia++;//Si se encuentra la palabra en el conjunto, entonces solo aumenta su frecuencia
    } else {
        totalPalabras++;
        //conjunto=(Nodo*)realloc(conjunto,sizeof(Nodo)*totalPalabras);
        conjunto[totalPalabras-1].frecuencia=1;//como apenas se agrega la palabra, su frecuencia será de 1
        strcpy(conjunto[totalPalabras-1].palabra,palabra);
    }
}

//Si encuentra la palabra en el conjunto, regresa su índice. Si no, regresa -1.
int buscar_palabra(char* palabra, Nodo* conjunto){
    int i;
    for (i=0; i<totalPalabras; i++){   
        if(!strcmp(conjunto[i].palabra, palabra)){
            return i;
        }
    }
    return -1; //regresa en caso de que no se encuentre
}

//Recibe el arreglo de palabras y lo regresa ordenado de mayor a menor frecuencia.
void ordenar_palabras(Nodo* conjunto){
    Nodo aux;
    int i;
    int j;
    for(i=totalPalabras-1; i>0; i--){
        int exchange = 0; //variable booleana para detener codigo en caso de que ya este ordenado
        for(j=0; j<i; j++){
            if(conjunto[j].frecuencia < conjunto[j+1].frecuencia){
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
    fprintf(archivo, "|      PALABRA       |      FRECUENCIA      |\n");
    int i;
    for (i = 0; i < totalPalabras; i++){
        fprintf(archivo, "|%-20s|%22i|\n", conjunto[i].palabra, conjunto[i].frecuencia);
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
    conjunto=(Nodo*)malloc(sizeof(Nodo)*900);
    
    FILE *archivoEntrada = fopen(nombreEntrada, "r");
    FILE *archivoSalida = fopen(nombreSalida, "w");
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
                limpiar_palabra(token);
                if (token[0] == '\0'){
                    token = strtok(NULL, " ");
                    continue;
                }
                contar_palabra(token, conjunto); // Contar la palabra y agregarla al conjunto
                token = strtok(NULL, " ");
            }
        }
        
    }
    ordenar_palabras(conjunto);
    guardar_palabras(conjunto,archivoSalida);
    fclose(archivoEntrada);
    fclose(archivoSalida);
    free(conjunto);
    return 0;
}
