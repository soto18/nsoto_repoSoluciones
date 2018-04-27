/*Algoritmo Narrado
 * Inicar una funcion para la cuenta total
 * Declarar las variables 
 * Iniciar un ciclo for dentro de la funcion 
 * Imprimir el pago del primer mes
 * Calcular el pago anterior
 * Se realiza:
 * 	pago_anterior= pago_anterior*2
 * Retornar el pago total
 * Iniciar la funcion main
 * Declar la variable pago total
 * Igualar la variable a la primera funcion
 * Imprimir el pago total
 * retornar cero
 * */
 #include <stdio.h>
 
int cuenta_total ()
{
	int i, pago_total=0, pago_anterior;
	
	pago_anterior =10;
	for (i=0; i < 20; i++){
		pago_total=pago_total+ pago_anterior;
		printf ("Para el mes %d su pago es de: %d\n", i+1,pago_anterior);
		pago_anterior= pago_anterior*2;	
	}
	return pago_total;
}
 
 
 int main ()
 { 
	int pago_total;
	
	pago_total =cuenta_total ();
	printf ("Pago total:%d", pago_total);
	return 0;
}
	
