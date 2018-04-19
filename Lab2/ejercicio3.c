/*Algoritmo narrado
 * Declar cuatro variables de tipo float
 * Pedir y guardar datos
 * calcular las unidades por dia
 * 	se realiza: unidades_por_dia = (cantidad_del_peso * 0.2);
 * Calcular las gotas
 * 	Se realiza: gotas= (unidades_por_dia *(2500)/500);
 * Calcular las gotas para un menor
 * 	Se realiza: gotas_para_menor= (gotas/3);
 * Mostrar la cantidad que se debe dar a juanito
 * Retorna 0
 * */
#include <stdio.h>
int main ()
{
	float cantidad_del_peso;
	float unidades_por_dia;
	float gotas;
	float gotas_para_menor;
	
	printf ("Ingrese el peso del niño en kilogramos:");
	scanf ("%f", &cantidad_del_peso);
	
	unidades_por_dia = (cantidad_del_peso * 0.2);
	gotas= (unidades_por_dia *(2500)/500);
	gotas_para_menor= (gotas/3);
	
	printf ("Juanito tiene menos de un año debe tomar %.2f\n",unidades_por_dia);
	printf ("Juanito es mayor a un año debe tomar %.2f\n", gotas_para_menor);
	return 0;
}
