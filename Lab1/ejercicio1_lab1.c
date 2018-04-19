/* Algoritmo narrado
 * Declarar seis variables de tipo int y una de tipo char
 * iniciar un ciclo (while) que termine al presionar f
 * Pedir y guardar los datos del voto
 * Dar la posiblidad de elegir un candidato
 * Optar a terminar el ingreso de votos
 * Ingresar la cantidad de votos
 * Indicar quien es el presidente electo
 * Retorna 0
 * */

#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int candidato1= 0;
	int candidato2= 0;
	int candidato3= 0;
	int voto;
	int votos=0;
	char fin='n';
	int votos_nulos=0;
	
	while (fin != 'f' ){
		printf ("Ingrese voto:");
		scanf ("%d",&voto);
		
		switch (voto)
		{
			case 1:
				candidato1 = candidato1 +1;
				votos++;
				break;
			case 2:
				candidato2 = candidato2 + 1;
				votos++;
				break;
			case 3:
				candidato3 = candidato3 +1;
				votos++;
				break;
			default:
				printf ("Voto nulo");
				votos_nulos++;
				votos++;
		}
		while (getchar() != '\n');
		printf ("¿Seguir ingresando votos?:");
		scanf ("%c", &fin);
	}	
	printf ("\n\nVotos candidato 1: %d\n", candidato1);
	printf ("Votos candidato 2: %d\n", candidato2);
	printf ("Votos candidato 3: %d\n", candidato3);
	printf ("Total de votos: %d\n", votos);
	printf ("Votos nulos: %d\n", votos_nulos);
	
	if (candidato1 >= candidato2 && candidato1 > candidato3){
		printf ("Presidente electo: candidato1");
	}
	else if (candidato3 >= candidato1 && candidato3 > candidato1){
		printf ("Presidente electo: candidato2");
	}
	else if (candidato3 >= candidato1 && candidato3 > candidato1){
		printf ("Presidente electo:candidato3");
	}
	else{
		printf ("No se puede determinar");
	} 
	return 0;
}
		
