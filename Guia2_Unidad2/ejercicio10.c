/*Del ejercicio anterior, incluya además la posibilidad de encontrar el patrón y transformar las minúsculas
por mayúsculas, por ejemplo si el usuario ha digitado tacaaat, en la cadena de ADN impreso en pantalla
debe mostrarse destacado como TACAAAT.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mayuscula(char secuencia[1000], int lensecuencia, char subsecuencia[100], int lensubsecuencia){
	int i, j;
	for (i=0; i<lensecuencia; i++){
		for (j=0; j<lensubsecuencia; j++){
			if(secuencia[i]==subsecuencia[j]){
				if (secuencia[i]==97){ 
				secuencia[i]=65;
				}
				if (secuencia[i]==116){
					secuencia[i]=84;
				}
				if (secuencia[i]==99){
					secuencia[i]=67;
				}
				else if (secuencia[i]==103){
					secuencia[i]=71;
				}	
			}
		}
	}
	printf("\n");
	return 0;
}	 	
		
int main (){
	int cambio;
	char secuencia [1000]="gtgggggggtttatgcctttagaacagcagactactgataactccaatcctgggttgaaaatgccaagggcgccagagagccaaacgatgagcgttggaccacaaacgataaaaactcactttctccgtggggtgaaagcgattctttctggcccgtatccgccagcacttaaagttgcattcggcgcggccctaccgctgctaattggggtaattgtcctaggattgtacgtaacgcttggcgggcacagccgcaagaaagcccacgcagccgcgatagatgctttggtcgagaagcacgaagcatgctacaaggtccaagcaaagattgcacacggcaggcttgccttacagtccgctgtggtgtctgttgcggatgccagcatgcaacaactccagttcgtgcagcaaggaattctcatgtgtgtcggagagctcgacgatatgcagaagttccggacccgactggataatgaaatcagtgccatcaaccagcgaattcccagcattgtcgaggaggtaagaaaacacaccgacgatgcgcttgagtggaatcttgctagaaccaagaacattttagagggcactgaagagcgcctgaaggatatgggcaatgagttggtgcgctacctagacgatgctcgcgccctcattgaaaatgcacgtatagctgcaggatcaatgcaacacctcgttggtgatgaggtgagaaagcagcttgctgaggttctagtaaaagttgcagaagtaagtaatggctttattgcgcttaagaagagtgtatctggctatttggaaaaaagcagtggacttgttgctagggaagttagggcaatcctggatgaccgcatgcgaagcctgcggaccatgtacaaaatgtgggatgcagaacaaaactccgtagtcagcgtgtgtaccacgctccaaaaggcaagcatggaggctgccgcggtagcaagt";
	char subsecuencia[100];
	
	printf ("Ingrese una subsecuencia (maximo 100 aminoacidos): ");
	scanf ("%s", subsecuencia);
	cambio = mayuscula(secuencia, strlen(secuencia), subsecuencia, strlen(subsecuencia));
	
	printf ("%d", cambio);
	printf("Secuecnia original: \n%s\n", secuencia); 
	mayuscula(subsecuencia, strlen(secuencia), subsecuencia, strlen(subsecuencia));
	printf ("Sub secuencia ingresada: %s\n", subsecuencia);
		
	return 0; 
}
