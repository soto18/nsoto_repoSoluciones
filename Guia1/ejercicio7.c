#include <stdio.h>
int main()
{
	int Dias;
	int Calculo;
	
	printf ("Numero de dias:\n");
	scanf  ("%d",&Dias);
	
	Calculo= (((Dias*24)*60)*60);
	printf ("Segundos:%d", Calculo);
	
	return 0;
}
