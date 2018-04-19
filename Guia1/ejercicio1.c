#include <stdio.h>
int main()
{

	float Nota_1;
	float Nota_2;
	float Nota_3;
	int Matricula;
	float Promedio;
	
	printf("Escribir matricula\n");
	scanf("%d", &Matricula);
	
	printf("Nota 1:\n");
	scanf("%f", &Nota_1);
	printf("Nota 2:\n");
	scanf("%f", &Nota_2);
	printf("Nota 3:\n");
	scanf("%f", &Nota_3);
	
	
	Promedio = (Nota_1 + Nota_2 + Nota_3) / 3;
	printf("Promedio %.1f", Promedio);
	
	return 0;
}

