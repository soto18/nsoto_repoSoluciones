/*Dada una matriz cuadrada A, un programa que permita detectar si dicha matriz es simétrica. Se considera que una matriz es simétrica si A[i,j] = A[j,i] y esto se cumple para todo i distinto de j. La simetrı́a es respecto a la diagonal principal.*/
#include <stdio.h>
void llenar_Matriz (int n, int matriz_a[n][n]){
	int i;
	int j;
	for (i=0; i<n; i++){
	printf ("\n");
		for (j=0; j<n; j++){
		printf("Ingrese el valor de la cordenada %d,%d: ",i+1,j+1);
		scanf ("%d", &matriz_a[i][j]);
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
void revisar_simetria (int n, int matriz_a[n][n]){
	int i;
	int j;
	int interruptor=0;
	
	for (i=0; i<n;i++){		
		for (j=0; j<n;j++){
			if (i!=j){
				if (matriz_a[i][j]==matriz_a[j][i]){
					interruptor=0;
				}
				else {
					interruptor = 1;

				}
			}
		}
	}
	if (interruptor==0){
		printf("\nLa matriz es simetrica");
	}
	
	else{
	printf("\nLa matriz no es simetrica");
	}
}
	
int main(){
	int n;
	printf ("Ingrese el tamaño de la matriz: ");
	scanf ("%d", &n);
	int matriz_a [n][n];
	
	llenar_Matriz (n, matriz_a);
	Imprimir_Matriz (n,matriz_a);
	revisar_simetria(n, matriz_a);
	return 0;
}

