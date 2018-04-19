#include <stdio.h>
int main()
{
	
	int comision;
	int ventas;
	int sueldo_base;
	int sueldo_total;
	
	printf ("Sueldo base:");
	scanf ("%d", &sueldo_base);
	
	printf ("Dinero de ventas:");
	scanf ("%d",&ventas);
	
	comision= ((ventas*7)/100);
	printf ("Comision: %d\n", comision);
	
	sueldo_total= (sueldo_base + comision);
	printf ("Sueldo total: %d\n", sueldo_total);
	
	return 0;
}
