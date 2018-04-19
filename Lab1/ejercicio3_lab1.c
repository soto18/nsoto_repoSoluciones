/* Algoritmo Narrado
 * Declarar tres variables de tipo float
 * Resivir y guardar datos
 * Indicar decuento
 * Calcular las posiblidades de descuento
 * Se realiza 15%:
 * descuento_de_15 = (0.85*precio_del_traje)
 * Se realiza 8%:
 * descuento_de_8 = (0.008*precio_del_traje)
 * Retorna 0
 * */
 
#include <stdio.h>

int main ()
{
	float precio_del_traje;
	float descuento_de_15;
	float descuento_de_8;
	
	printf ("Precio del traje:");
	scanf ("%f", &precio_del_traje);
	
	if (precio_del_traje > 2500.00){
		printf ("Traje con descuento \n");
		descuento_de_15 = (0.85*precio_del_traje);
		printf ("El precio traje: %f",descuento_de_15);
		
	}
	
	else if (precio_del_traje <=2500.00){
		printf ("Traje con descuento \n");
		descuento_de_8 = (0.008*precio_del_traje);
		printf ("Precio traje: %f",descuento_de_8);
	}
	
	return 0;
}
		
