/*Escriba un programa que cree una matriz cuadrada A de NxN, luego rellénela de ceros e imprı́mala en pantalla. Con N=6*/
#include <stdio.h>
int tamanioMatriz(){
	int n;
	printf ("Ingrese el tamaño de la matriz: ");
	scanf ("%d",&n);
	return n;
}
void llenar_Matriz (int n, int matriz_a[n][n]){
	int i;
	int j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){
			matriz_a[i][j]=0;
		}
	}	
}
void Imprimir_Matriz (int n, int matriz_a[n][n]){
	int i;
	int j;
	printf ("\n");
	for (i=0; i<n; i++){
		printf ("\t(%d)",i+1);
	}
	for (i=0; i<n; i++){
		printf ("\n");
		printf ("(%d)",i+1);
		for (j=0; j<n; j++){
			printf ("\t %d",matriz_a[i][j]);
		}
	}	
}
int main (){
	int n;
	n= tamanioMatriz();
	int matriz_a [n][n];
	llenar_Matriz (n, matriz_a);
	Imprimir_Matriz(n, matriz_a);
	
		return 0;
	
}
