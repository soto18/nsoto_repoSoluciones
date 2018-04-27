/* Algoritmo narrado
 * Declarar las variables de tipo int
 * Crear una funcioón para calcular el sueldo total
 * Crear una funcion para escribir el sueldo total
 * Iniciar la funcion main
 * Declarar la variables 
 * Iniciar un ciclo for 
 * Calcular el total de horas
 * Pedir el sueldo por las horas trabajadas
 * Llamar a la primera funcion
 * Llamar a la segunda funcion
 * retornar cero
 * */
#include <stdio.h>
int sueldo (int sueldo_horas, int horas_del_dia){
	int sueldo_total;
	sueldo_total= (horas_del_dia* sueldo_horas);
	return sueldo_total;
}
	 
void sueldo_persona (int sueldo_total){
	printf ("Sueldo recibido: %d\n", sueldo_total);
}
	 
int main()
{
	int horas;
	int sueldo_horas;
	int total_de_horas=0;
	int sueldo_total=0;
	int a;
	
	
	for (a=0; a<6; a++){
		printf ("Horas trabajadas en el día %d:", a+1);
		scanf ("%d", &horas);
		total_de_horas= total_de_horas + horas;
	}
	
	printf ("Ingrese sueldo por horas trabajadas:");
	scanf ("%d", &sueldo_horas);
	sueldo_total = sueldo (sueldo_horas, total_de_horas);
	
	sueldo_persona(sueldo_total);
	
	return 0;
}
			
