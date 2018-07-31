/*Cree una matriz cuadrada A de NxN, luego pida al usuario rellenarla. Al final del proceso, entregue al un resumen con: La matriz, la sumatoria de los valores de sus filas y luego la sumatoria de los valores de toda la matriz.*/
#include <stdio.h>
void Imprimir_matriz (int n, int matriz [n][n]){
	int i;
	int j;
	
	printf ("\n");
	for (i=0;i<n; i++){
		printf ("\t(%d)", i+1);
	}
	for (i=0; i<n; i++){
		printf ("\n");
		printf ("(%d)", i+1);
		for (j=0; j<n; j++){
			printf ("\t %d", matriz [i][j]);
	}
}
}
void Llenar_matriz (int n, int matriz [n][n]){
	int i;
	int j;
	for (i=0; i<n; i++){
		printf ("\n");
			for (j=0; j<n; j++){
			printf("Ingrese el valor de la cordenada %d,%d: ",i,j);
			scanf ("%d", &matriz[i][j]);
		}
	}
}
void sumaMatriz (int n, int matriz [n][n]){
	int i;
	int j;
	int suma=0;
	
	printf ("\n");
	for (i=0;i<n;i++){
		int suma_filas=0;
		for (j=0;j<n;j++){
			suma_filas+= matriz [i][j];
			suma+= matriz [i][j];
	}
	printf ("\nSuma fila (%d): %d", i+1,suma_filas);
}
	printf ("\nSuma matriz: %d", suma);
}
int main (){
	int n; 
	
	printf ("Ingrese el tamaño para la matriz: ");
	scanf ("%d", &n);

	int matriz [n][n];
	Llenar_matriz (n, matriz);
	Imprimir_matriz (n, matriz);
	sumaMatriz (n, matriz);

	
	return 0;
}
 

