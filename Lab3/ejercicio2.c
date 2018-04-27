/*Algortimo narrado
 * Crear un procedimiento que muestre el estado del termometro
 * Crear una funcion para pedir la temperatura
 * Iniciar la funcion main
 * Llamar al procedimiento
 * Llamar a la funcion
 * Retonar cero
 * */
#include <stdio.h>

void Estado_termometro (int n){
	printf ("0         10        20        30        40        50\n");
	printf ("|         |         |         |         |         |\n");

	int i;
	for (i=0; i < n; i++){
		printf ("-");
	}
	printf("*");
}

int solicitar_temperatura (){
	int temperatura;
	printf ("Ingrese la temperatura: ");
	scanf ("%d", &temperatura);
	
	return temperatura;
}

int main (){
	int temperatura = solicitar_temperatura();
	
	Estado_termometro(temperatura);
	
	return 0;
}
