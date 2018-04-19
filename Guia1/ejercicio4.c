#include <stdio.h>
int main ()
{
	int altura= 8;
	int base= 5;
	int periodo;
	int superficie;

	periodo= (2*(base + altura));
	printf ("periodo:%d\n", periodo);
	
	superficie= (base * altura);
	printf ("superficie:%d\n", superficie);
	
	return 0;
}
