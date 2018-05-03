/* Algoritmo narrado
 * Iniciar una funcion 
 * Declarar las variables
 * Pedir y guaradar los datos
 * Calcualar los huevos por personas
 * Calcualar el porcentaje de huevo para juan y manuel
 *Calcular el pago para juan y manuel
 * retornar cero
 * inicar int main 
 * Llamar a la funcion
 * retornar cero
 *  */
 #include <stdio.h>
 
float dinero_a_pagar (){
	float huevos;
	float personas;
	float huevos_a_comer;
	float valor_huevos =10;
	float juan=5;
	float manuel=3;
	float porcentaje_para_manuel;
	float porcentaje_para_juan;
	float pago_juan;
	float pago_manuel;
	
	printf ("Ingrese numero de huevos:");
	scanf ("%f", &huevos);
	printf ("Ingrese numero de personas:");
	scanf ("%f", &personas);
	
	printf ("\n");
	huevos_a_comer = huevos/personas;
	printf  ("Huevos a comer cada uno: %f\n", huevos_a_comer);
	
	porcentaje_para_manuel= (manuel-huevos_a_comer);
	printf ("Porcentaje de huevo que manuel le dio a antonio %f\n", porcentaje_para_manuel);
	
	porcentaje_para_juan= (juan - huevos_a_comer);
	printf ("Porcentaje de huevo que juan le dio a antonio%f\n\n", porcentaje_para_juan);
	
	pago_manuel= porcentaje_para_manuel* valor_huevos;
	printf ("Se debe pagar %f a Manuel\n", pago_manuel);
	
	pago_juan = (porcentaje_para_juan * valor_huevos);
	printf ("Se debe pagar %f a Juan\n", pago_juan);
	
	return 0;
}

int main (){
		
	dinero_a_pagar ();
	return 0;
	}
