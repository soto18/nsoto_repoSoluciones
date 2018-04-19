#include <stdio.h>
int main ()
{
	float x;
	float ejercicio;
	
	printf ("Valor de x:\n");
	scanf ("%f", &x);
	
	ejercicio = (x*x*x) + 2*(x*x) + 3*(x) +5;
	printf ("Resultado:%.1f",ejercicio);
	
	return 0;
}		
