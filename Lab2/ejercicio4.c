/*
 * Algoritmo  narrado
 * Declarar 4 variables de tipo int 
 * Iniciar un ciclo for
 * Pedir y guardar los datos
 * Agregar condicionales para indicar si es ganar, empate o pierde
 * Se cuentan todos los puntos
 * Retorna 0
 * */
 #include <stdio.h>
 int main()
 {
	 int resultado_equipo=0;
	 int resultado_contrincante=0;
	 int puntos=0;
	 int i=0;
	 
	 for (i=0; i<=5; i++) {
	 printf ("Resultado del equipo:");
	 scanf ("%d", &resultado_equipo);
	 printf ("Resultado del contrincante:");
	 scanf ("%d", &resultado_contrincante);
	 
		if (resultado_equipo > resultado_contrincante){
			puntos +=3;
			printf ("Ganador nuestro equipo\n");
		}
		else if (resultado_equipo == resultado_contrincante){
			puntos ++;
			printf ("Empate\n");
		}
		else {
			printf ("Derrota\n");
		}
	}
	 printf ("Puntos hasta el quinto partido: %d", puntos);
	 
	return 0;
}
	 
