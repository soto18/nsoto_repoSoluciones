#include <stdio.h>
int main()
{
	
	int galones;
	float cantidad_de_litros;
	int valor_del_litro;
	
	printf ("Ingrese galones vendidos:");
	scanf ("%d",&galones);
	
	cantidad_de_litros= (galones * 3.785);
	printf ("Cantidad de litros: %.3f\n", cantidad_de_litros);
	
	valor_del_litro = (cantidad_de_litros * 820);
	printf ("Precio del litro: %d\n",valor_del_litro);
	
	return 0;
}
