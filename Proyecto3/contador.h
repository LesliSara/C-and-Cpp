#ifndef CONTADOR_H
#define CONTADOR_H

    struct nodo {           //Estructura con los elementos del arreglo.
    	char palabra[32];  //Palabra que se leyó del archivo.
		int frecuencia;     //Cantidad de veces que apareció la palabra.
    };
    typedef struct nodo Nodo;   //typedef para facilitar la declaración de estructuras.

    //En esta implementación, el tamaño del arreglo de estructuras Nodo se guarda como una variable global en el archivo "contador.c".

    void limpiar_palabra(char* palabra);                //Recibe una cadena, la convierte toda a minúsculas y le quita puntos (.), comas (,) y letras 's'.
    void contar_palabra(char* palabra, Nodo* conjunto);   //Si la palabra está en el conjunto, incrementa su frecuencia. Si no, la agrega. En cualquiera de los dos casos, regresa el conjunto actualizado.
    int buscar_palabra(char* palabra, Nodo* conjunto);     //Si encuentra la palabra en el conjunto, regresa su índice. Si no, regresa -1.
    void ordenar_palabras(Nodo* conjunto);              //Recibe el arreglo de palabras y lo regresa ordenado de mayor a menor frecuencia.
    void guardar_palabras(Nodo* conjunto, FILE *archivo); //Guarda el arreglo de palabras en un archivo.

#endif
