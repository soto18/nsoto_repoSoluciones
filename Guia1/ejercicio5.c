#include <stdio.h>
int main ()
{
	char nombre[70];
	float peso;
	float longitud;
	float libras;
	float pies;

	printf("Ingresa nombre del dinosaurio:\n");
	scanf("%s", nombre);
	
	printf ("Libras:");
	scanf ("%f",&libras);
	printf ("Pies:");
	scanf ("%f",&pies);
	
	peso= (libras * 0.45);
	printf("Resultado peso: %.2f kilos\n",peso);
	
	longitud= (pies * 0.3048);
	printf("Resultado longitud: %.4f metros\n",longitud);
	
	printf("El nombre del dinosaurio es: %s", nombre);
	
	return 0;
}
	
