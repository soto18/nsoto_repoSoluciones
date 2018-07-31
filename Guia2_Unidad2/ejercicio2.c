/*Escriba un programa que cree una matriz cuadrada A de NxN, luego rellénela de ceros y asigne 1 en su diagonal principal 1 . En otras palabras genere una matriz identidad 2 de 6x6. Con N=6*/
#include <stdio.h>
int tamanioMatriz(){
	int n;
	printf ("Ingrese el tamaño de la matriz: ");
	scanf ("%d",&n);
	return n;
}
	
void llenar_matriz(int n, int Matriz_a [n][n]){
	
	int i,j;
	for (i=0; i<n; i++){
		for (j=0; j<n; j++){	
			if (i==j){
				Matriz_a[i][j]=1;
			}
			else{
				Matriz_a[i][j]=0;
			}
		}
	}
}

void imprimir_matriz(int n, int Matriz_a [n][n]){
	int i,j;
	printf ("\n");
	for (i=0; i<n; i++){
		printf ("\t(%d)", i+1);
	}
	
	for (i=0; i<n; i++){
		printf ("\n");
		printf ("(%d)",i+1);
		for (j=0; j<n; j++){	
			printf ("\t %d",Matriz_a[i][j]);
		}
	}
}

int main (){
	int tamanio;
	tamanio = tamanioMatriz();
	int Matriz_a[tamanio][tamanio];
	llenar_matriz (tamanio, Matriz_a);
	imprimir_matriz (tamanio, Matriz_a);
	return 0;
}
