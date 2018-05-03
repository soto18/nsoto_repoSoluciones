/* Algoritmo narrado
 * Iniciar una funcion (numero inverso)
 * Dentro de la funcion pedir el numero y guardar los datos
 * Escribir el mod del numero
 * dividir el numero en 10
 * calcular el mod del resultado de la division
 * dividir el resultado de la division en 10
 * escribir el mod de la ultima division
 * retornar 0
 * iniciar la funcion int main
 * llamar a la funcion
 * retornar 0
 * */
 #include <stdio.h>

int numero_inverso (){
	int numero, division, division2;
	printf ("Ingrese un número de máximo tres digitos:");
	scanf ("%d", &numero);
	
	printf ("%d", (numero%10));
	division = (numero/10);
	printf ("%d", (division%10));
	division2 = (division/10);
	printf ("%d", (division2%10));
	
	
	return 0;
}

int main () {

	numero_inverso();
	return 0;
}
	
	
	
