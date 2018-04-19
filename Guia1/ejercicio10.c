#include <stdio.h>
int main()
{
	int kilometros;
	int costo_por_kilometro;
	int costo_boleto;
	
	printf ("Cantidad de kilometros:");
	scanf ("%d",&kilometros);
	printf ("Costo_por_kilometro:");
	scanf ("%d",&costo_por_kilometro);
	
	costo_boleto= (kilometros *costo_por_kilometro);
	printf ("Costo_boleto: %d\n", costo_boleto);
	
	return 0;
}
