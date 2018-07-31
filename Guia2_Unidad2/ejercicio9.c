#include <stdio.h>
#include <string.h>

void buscarPatron(char secuencia[1000], char patron[100]) {
	int i;
	int contador=0;
	
	if (strstr(secuencia, patron)) {
		printf("\nEl patron <%s> SI fue encontrado.\n", patron);
		for (i=0; i<strlen(secuencia); i++){
			secuencia[i]=patron [i];
			contador++;
		}
			
	}
	else {
		printf("\nEl patron <%s> NO fue encontrado.\n", patron);
	}
	printf ("Hay %d coincidencias", contador);
} 


int main() {
	char dna[1000] = {"gtgggggggtttatgcctttagaacagcagactactgataactccaatcctgggttgaaaatgccaagggcgccagagagccaaacgatgagcgttggaccacaaacgataaaaactcactttctccgtggggtgaaagcgattctttctggcccgtatccgccagcacttaaagttgcattcggcgcggccctaccgctgctaattggggtaattgtcctaggattgtacgtaacgcttggcgggcacagccgcaagaaagcccacgcagccgcgatagatgctttggtcgagaagcacgaagcatgctacaaggtccaagcaaagattgcacacggcaggcttgccttacagtccgctgtggtgtctgttgcggatgccagcatgcaacaactccagttcgtgcagcaaggaattctcatgtgtgtcggagagctcgacgatatgcagaagttccggacccgactggataatgaaatcagtgccatcaaccagcgaattcccagcattgtcgaggaggtaagaaaacacaccgacgatgcgcttgagtggaatcttgctagaaccaagaacattttagagggcactgaagagcgcctgaaggatatgggcaatgagttggtgcgctacctagacgatgctcgcgccctcattgaaaatgcacgtatagctgcaggatcaatgcaacacctcgttggtgatgaggtgagaaagcagcttgctgaggttctagtaaaagttgcagaagtaagtaatggctttattgcgcttaagaagagtgtatctggctatttggaaaaaagcagtggacttgttgctagggaagttagggcaatcctggatgaccgcatgcgaagcctgcggaccatgtacaaaatgtgggatgcagaacaaaactccgtagtcagcgtgtgtaccacgctccaaaaggcaagcatggaggctgccgcggtagcaagt"}; 
	printf("\nSecuencia principal:\n> %s\n", dna);
	
	char patron[100]; 
	printf ("\nIngresa el patron a buscar (max 100 caracteres): ");
	gets(patron); 

	buscarPatron(dna, patron);

	return 0;
}

//El ejercicio no cuenta la cantidad correcta de coincidencia
