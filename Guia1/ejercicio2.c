#include  <stdio.h>

 int main()
 {
	 int numero;
	 int cuadrado;
	 int cubo;
	 
	 printf ("Escribir numero:\n");
	 scanf ("%d",&numero);
	 
	 cuadrado = (numero * numero);
	 printf ("Resultado cuadrado: %d\n",cuadrado);
	 
	 cubo= (cuadrado * numero);
	 printf ("Resultado cubo: %d", cubo);
	 
	 return 0;
 }
