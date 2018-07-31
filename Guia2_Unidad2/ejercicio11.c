/*Ordene utilizando algún método la cadena de ADN.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void ordenamientoInsercion (char adn[] , int n){
	int i,j;
	int auxiliar;
	for (i=1; i<n; i++){
		j=i;
		auxiliar=adn[i];
		while (j>0 && auxiliar<adn[j-1]){
			adn[j]=adn[j-1];
			j--;
		}
		adn[j]=auxiliar;
	}
}

void seleccion(char adn[], int n){
	int indice_menor,i,j;
	for(i=0;i<n-1;i++){
		indice_menor=i;
		for(j=i+1;j<n;j++){
			if (adn[j]<adn[indice_menor])
			indice_menor=j;
			if(i!= indice_menor){
				int auxiliar=adn[i];
				adn[i]=adn[indice_menor];
				adn[indice_menor]=auxiliar;
			}
		}		
	}	
}

int main(){
	char adn[10000]={"gtgggggggtttatgcctttagaacagcagactactgataactccaatcctgggttgaaaatgccaagggcgccagagagccaaacgatgagcgttggaccacaaacgataaaaactcactttctccgtggggtgaaagcgattctttctggcccgtatccgccagcacttaaagttgcattcggcgcggccctaccgctgctaattggggtaattgtcctaggattgtacgtaacgcttggcgggcacagccgcaagaaagcccacgcagccgcgatagatgctttggtcgagaagcacgaagcatgctacaaggtccaagcaaagattgcacacggcaggcttgccttacagtccgctgtggtgtctgttgcggatgccagcatgcaacaactccagttcgtgcagcaaggaattctcatgtgtgtcggagagctcgacgatatgcagaagttccggacccgactggataatgaaatcagtgccatcaaccagcgaattcccagcattgtcgaggaggtaagaaaacacaccgacgatgcgcttgagtggaatcttgctagaaccaagaacattttagagggcactgaagagcgcctgaaggatatgggcaatgagttggtgcgctacctagacgatgctcgcgccctcattgaaaatgcacgtatagctgcaggatcaatgcaacacctcgttggtgatgaggtgagaaagcagcttgctgaggttctagtaaaagttgcagaagtaagtaatggctttattgcgcttaagaagagtgtatctggctatttggaaaaaagcagtggacttgttgctagggaagttagggcaatcctggatgaccgcatgcgaagcctgcggaccatgtacaaaatgtgggatgcagaacaaaactccgtagtcagcgtgtgtaccacgctccaaaaggcaagcatggaggctgccgcggtt"};
	printf ("\n\t_____________SECUENCIA ORIGINAL______\n");
	printf ("\n");
	printf("%s\n\n ",adn);		
	ordenamientoInsercion(adn, strlen(adn));
	printf ("\n\t_____________ORDENAMIENTO_____________\n");
	printf ("\n");
	printf ("%s\n", adn);
		
	return 0;
}

