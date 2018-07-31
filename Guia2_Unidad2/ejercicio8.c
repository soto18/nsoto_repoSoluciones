/*Construya un programa en C que intercambie los renglones de una arreglo bidimensional. Los elementos del renglón 1 deben intercambiarse con el del renglón N, los del renglón 2 con los del renglón N-1, y ası́ sucesivamente.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void llenar_matriz(int n, int matriz[n][n] ){
	 srand(time(NULL));
	int i;
	int j;
	int num;
	for(i=0; i<n;i++){
		for (j=0; j<n; j++){
			num = 1+(rand()%20);
			matriz[i][j]=num;
		}
	}

}
void imprimir_matriz(int n, int matriz [n][n]){
	int i, j;
	printf ("MATRIZ ORIGINAL\n\n");
	for(i=0; i<n;i++){
		for (j=0; j<n; j++){
			printf("\t%d", matriz[i][j]);
		}
		printf("\n");
	}

}
void cambio(int n, int matriz[n][n]){
	int i;
	int j;
	printf ("MATRIZ CAMBIADA\n");
	for (i=n-1; i>=0; i--){
		for (j=0; j<n;j++){
			printf ("\t%d", matriz [i][j]);
		}
		printf ("\n");
	}
}
	
int main (){
	srand(time(NULL));
	int n;
	printf ("Ingrese el tamaño de la matriz:");
	scanf ("%d",&n);
	int matriz[n][n];
	llenar_matriz(n, matriz);
	imprimir_matriz(n, matriz);
	cambio(n, matriz);
	
	return 0;
}

