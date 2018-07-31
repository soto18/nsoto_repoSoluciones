/*Dada una matriz A (MxN) de tipo entero, construya un programa para calcular la Traspuesta de dicha matriz. La traspuesta de una matriz se obtiene al escribir las filas de la matriz A como columnas.*/
#include <stdio.h>
void Llenar_Matriz (int fila,int columna, int Matriz_A[fila][columna]){
	int i;
	int j;
	for (i=0; i<fila; i++){
	printf ("\n");
		for (j=0; j<columna; j++){
		printf("Ingrese el valor de la cordenada %d,%d: ",i+1,j+1);
		scanf ("%d", &Matriz_A[i][j]);;
		}
	}
}
void Imprimir_original (int fila,int columna, int matriz_a[fila][columna]){
	int i;
	int j;
	printf ("\n");
	printf ("Matriz original\n");
	for (i=0; i<columna; i++){
		printf ("\t(%d)",i+1);
	}
	for (i=0; i<fila; i++){
		printf ("\n");
		printf ("(%d)",i+1);
		for (j=0; j<columna; j++){
			printf ("\t %d",matriz_a[i][j]);
		}
	}	
}
void Imprimir_Traspuesta (int fila, int columna, int Matriz_A[fila][columna]){
	int i;
	int j;
	printf ("\n");
	printf ("\nMatriz traspuesta\n");
	for (i=0; i<fila; i++){
		printf ("\t(%d)",i+1);
	}
	for (i=0; i<columna; i++){
		printf ("\n");
		printf ("(%d)",i+1);
		for (j=0; j<fila; j++){
			printf ("\t %d",Matriz_A[j][i]);
		}
	}	
}
int main(){
	int fila;
	int columna;
	printf ("Ingrese el numero de filas que desea:");
	scanf ("%d",& fila);
	printf ("Ingrese el numero de columnas que desea:");
	scanf ("%d", &columna);
	
	int Matriz_A [fila][columna];
	
	Llenar_Matriz(columna,fila, Matriz_A);
	Imprimir_original (fila, columna, Matriz_A);
	Imprimir_Traspuesta (fila,columna, Matriz_A);
	return 0;
}
