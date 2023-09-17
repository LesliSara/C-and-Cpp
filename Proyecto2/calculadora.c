#include <stdio.h>
#include <string.h>
#include "operaciones.h"

int main(){
	int n=100, aux;
    float datos[n];
    char opcion[20], opcion2[20];

    inicializar(datos, n); //pone 0 en todo el arreglo

    ver_comandos();
    while (1)
    {
        printf(">");
        fflush(stdin);
        scanf("%s", opcion);

        if (!strcmp("ayuda", opcion))
        {
            ver_comandos();
        }else if (!strcmp("salir", opcion))
        {
            break;
        }else if (!strcmp("n", opcion))
        {
            printf("Tu numero de elementos para el arreglo es n=%d", n);
            printf("Teclear por cual 'n' vas a cambiar , n=");
            scanf("%d", &aux);
            cambiar_n(&n, aux);
            printf("Tu numero de elementos para el arreglo ha cambiado a n=%d", n);
        }else if (!strcmp("datos", opcion))
        {
            llenar(datos, n);
        }else if (!strcmp("cambiar", opcion))
        {
            while (1)
            {
                printf("Escoja la casilla del arreglo que va a modificiar, puede desde la posicion 1, hasta la %d:", n);
                scanf("%d", aux);
                printf("Desea cambiar este valor Dato[%d]: %.4f ? [yes/no (teclear otra cosa)]: ", aux, datos[aux-1]);
                fflush(stdin);
                scanf("%s", opcion2);
                if (strcmp("yes", opcion2))
                {
                    printf("Ingrese el nuevo numero: ");
                    scanf("%d", datos[aux-1]);
                    printf("Se hizo el siguiente cambio Dato[%d]: %.4f ", aux, datos[aux-1]);
                    break;
                }
            }
            
        }else if (!strcmp("imprimir", opcion))
        {
            bubbleSort(datos, n);
            imprimir(datos, n);
        }else if (!strcmp("media", opcion))
        {
            printf("La media del arreglo es: %.4f", media(datos, n));
        }else if (!strcmp("mediana", opcion))
        {
            printf("La mediana del arreglo es: %.4f", mediana(datos, n));
        }else if (!strcmp("moda", opcion))
        {
            float mod=moda(datos, n);
            if (mod!=-1)
                printf("La moda es: %.4f", mod);
            else
                printf("No hay moda");
        }else if (!strcmp("varianza", opcion))
        {
            printf("La varianza del arreglo es: %.4f", varianza(datos, n));
        }else if (!strcmp("desvest", opcion))
        {
            printf("La deviacion estandar del arreglo es: %.4f", des_estandar(datos, n));
        }else if (!strcmp("cuartil_1", opcion))
        {
            printf("El primer cuartil del arreglo es: %.4f", cuartil_1(datos, n));
        }else if (!strcmp("cuartil_3", opcion))
        {
            printf("El tercer cuartil del arreglo es: %.4f", cuartil_3(datos, n));
        }else if (!strcmp("ric", opcion))
        {
            printf("El rango intercuartil del arreglo es: %.4f", rango_intercuartil(datos, n));
        }else if (!strcmp("rango", opcion))
        {
            printf("El rango del arreglo es: %.4f", rango(datos, n));
        }else if (!strcmp("todos", opcion))
        {
            todo(datos, n);
        }else
        {
            printf("Opcion incorrecta, vuelve a intentar\n");
        }
        
        
    }
    
}
