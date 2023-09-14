#include <stdio.h>

int main (){
	
	float num1, num2;
	//Primera parte que solicita los números
	printf ("Ingrese el primer numero: ");
	scanf("%f", &num1);
	printf ("Ingrese el segundo numero: ");
	scanf("%f", &num2);
	printf("Sus numeros ingresados fueron: %.4f %.4f", num1, num2);
	//Tabla
	printf("\n\t|    OPERACION    |    RESULTADO    |");
	printf("\n\t|-----------------|-----------------|");
	printf("\n\t|SUMA             |%17.4f|", num1+num2);
	printf("\n\t|RESTA            |%17.4f|", num1-num2);
	printf("\n\t|MULTIPLICACION   |%17.4f|", num1*num2);
	printf("\n\t|DIVISION         |%17.4f|\n\n", num1/num2);
	
	return 0;
	
}
