/* Algoritmo narrado
 * Declarar tres variables de tipo int 
 * Pedir y guardar datos
 * Añadir un ciclo for 
 * DEntro de un ciclo for añadir otro para determinar los divisores del numero
 * Dentro del ciclo agregar una condicion para determinar si el numero es primo
 * Contar la cantidad de numeros primos en el intervalo de numeros desde 1 hasta el dato pedido
 * Mostrar la cantidad de primos
 * retorna 0
 * */

#include <stdio.h>
int main ()
{
	int divisores;
	int dato_del_numero;
	int i;
	int k;
	int cont=0;
	
	printf ("Ingrese un numero menor a 1000000:");
	scanf ("%d", &dato_del_numero);
	
	for (k=2; k<=dato_del_numero; k++)
	{
		divisores=0;
		for (i=1; i<=dato_del_numero; i++)
		{
			if (k%i ==0)	
			{
				divisores++;
			}
		}
		if (divisores==2)
		{
			printf ("%d", k);
			cont++; 
		}	
	}
	printf ("Cantidad de numeros primos: %d", cont);
	return 0;
}
	
	
