#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //biblioteca que contiene isalpha
#include <string.h>
#include "contador.h"

Nodo *conjunto;

//Recibe una cadena, la convierte toda a minúsculas y le quita puntos (.), comas (,) y letras 's'.
void limpiar_palabra(char* palabra){
    printf("%s\n", palabra);
    int j=0;
    for(int i=0; i<strlen(palabra); i++){
        if (isalpha(palabra[i])){
            palabra[j++]=tolower(palabra[i]);
        }
        
    }
    palabra[j]='\0';
}

/*Si la palabra está en el conjunto, incrementa su frecuencia. 
Si no, la agrega. En cualquiera de los dos casos, regresa el conjunto actualizado.*/
Nodo *contar_palabra(const char* palabra, Nodo* conjunto){

}

//Si encuentra la palabra en el conjunto, regresa su índice. Si no, regresa -1.
int buscar_palabra(const char* palabra, Nodo* conjunto){

}

//Recibe el arreglo de palabras y lo regresa ordenado de mayor a menor frecuencia.
Nodo *ordenar_palabras(Nodo* conjunto){

}

//Guarda el arreglo de palabras en un archivo.
void guardar_palabras(const Nodo* conjunto, FILE *archivo){

}

int main(){
    char palabra[] = "kakKAKAKA ";
    limpiar_palabra(palabra);
    printf("%s", palabra);
    return 0;
}
