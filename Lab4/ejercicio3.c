/* Algoritmo narrado
 * 
 * 
 * */
 #include <stdio.h>

float probabilidad_de_infeccion (){
	float poblacion =10000;
	float porcentaje = 0.01;
	float resultado;
	
	resultado= (1/poblacion)* porcentaje;
	printf ("La probablidad de que una persona este infectada es de %f", resultado);
	
	return 0;
}
int main (){
	probabilidad_de_infeccion();
	
	return 0;
}
