/*Cree un programa que lea los elementos de una matriz de 4 X 5 y genere un vector de largo 4 en el que cada elemento contenga la sumatoria de los elementos de cada fila. El programa debe mostrar la matriz original y el vector en este formato (evidentemente, los valores deben ser los que correspondan a lo introducido por el usuario)*/
#include <stdio.h>
void Imprimir_matriz (int Matriz [4][5]){
	int i;
	int j;
	
	printf ("\n");
	for (i=0;i<5; i++){
		printf ("\t(%d)", i+1);
	}
	for (i=0; i<4; i++){
		printf ("\n");
		printf ("(%d)", i+1);
		for (j=0; j<5; j++){
			printf ("\t %d", Matriz [i][j]);
	}
}
}
void Llenar_matriz (int Matriz [4][5]){
	int i;
	int j;
	for (i=0; i<4; i++){
		printf ("\n");
			for (j=0; j<5; j++){
			printf("Ingrese el valor de la cordenada %d,%d: ",i+1,j+1);
			scanf ("%d", &Matriz[i][j]);
		}
	}
}
void Elementos_vector (int Matriz [4][5], int vector[4]){
	int i;
	int j;
	
	printf ("\n");
	printf ("\nElementos resultantes de la suma:\n");
	for (i=0;i<4;i++){
		int suma_filas=0;

		for (j=0;j<5;j++){
			suma_filas+= Matriz [i][j];
			}
		vector [i]= suma_filas;
		printf ("[%d] corresponde a la fila %d\n", vector[i],i+1);
	}
	
}
int main(){
	int Matriz[4][5];
	int vector [4];
	Llenar_matriz (Matriz);
	Imprimir_matriz (Matriz);
	Elementos_vector(Matriz, vector);
	
return 0;
}
