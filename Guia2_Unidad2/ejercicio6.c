#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define dia 7
#define hora 24
#define dia_por_semana 168
void llenado(int temperatura[dia][hora]){
	int i;
	int j;
	int valor;

	for (i=0; i<dia; i++){
		for (j=0; j<hora;j++){
			//~ printf ("Día %d\n", i+1);
			//~ printf ("Ingrese la temperatura en °C en la hora %d: ", j+1);
			//~ scanf ("%d",& temperatura[i][j]);
			valor= (rand()%40)+1;
			temperatura[i][j]= valor;
		}
	}
}

void Imprimir(int temperatura[dia][hora]){
	int i;
	int j;
	
	for (i=0; i<dia; i++){
		printf ("\n");
		for (j=0;j<hora; j++){
			printf (" %d ", temperatura[i][j]);
		}
	}
}

void t_minima(int temperatura[dia][hora]){
	int i;
	int j;
	int menor= 50;
	int minima[dia];
	for (i=0; i<dia; i++){
		menor=50;
		for (j=0; j<hora; j++){
			if (menor>temperatura[i][j]){
				menor=temperatura[i][j];
			}
		}
		minima[i] = menor;
		printf ("\nLa menor temperatura del dia %d es %d °C", i+1, menor);
	}
	
	printf ("\n");
	for (i=0; i<dia;i++){
		if (menor>minima[i]){
			menor=minima[i];
			}
		
	}
	printf ("\nLa menor temperatura de la semana es %d °C\n", menor);
}
void t_maxima(int temperatura[dia][hora]){
	int maxima[dia];
	int i;
	int j;
	int mayor=0;
	for (i=0; i<dia; i++){
		mayor=0;
		for (j=0; j<hora; j++){
			if (mayor<temperatura[i][j]){
				mayor= temperatura[i][j];
			}
		}
		maxima[i] = mayor;
		printf ("\nLa mayor temperatura del dia %d es %d °C", i+1, mayor);
	}
	for (i=0; i<dia;i++){
		if (mayor<maxima[i]){
			mayor=maxima[i];
			}
	}
	printf ("\n\nLa mayor temperatura de la semana es %d °C\n", mayor);
}
void t_media(int temperatura[dia][hora]){
	int i;
	int j;
	int media_dia;
	int dia_mayor_treinta=0;
	int suma_semanal=0;
	for (i=0; i<dia; i++){
		int suma=0;
		for(j=0; j<hora; j++){
			suma+= temperatura[i][j];
			suma_semanal+= temperatura[i][j];
		
		}
		media_dia = suma/hora	;
		printf("\nTemperatura media de la dia %d es %d",i+1, media_dia);
		if (media_dia > 30){
				dia_mayor_treinta+=1;
			}
	}
	
	printf("\n\nTemperatura media de la semana es, %d\n", suma_semanal/dia_por_semana);
	printf ("Dias que superan la media de 30 °C: %d", dia_mayor_treinta);
}
int main (){
	srand(time(NULL));
	int temperatura[dia][hora];
	llenado(temperatura);
	Imprimir (temperatura);
	t_maxima(temperatura);
	t_minima(temperatura);
	t_media(temperatura);

	
	
	return 0;
}
