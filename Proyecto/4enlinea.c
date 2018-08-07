#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ficha1 88 
#define ficha2 79
//Utilizada para colorear y formar el tablero con 
void imprimir_tablero (int tablero [8][8]){
	int i;
	int j;
	printf ("\n\n");
	for (i=0; i<8; i++){
		printf ("\t %d", i+1);
	}
	for (i=0; i<8; i++){
		printf ("\n\n");
		for(j=0; j<8; j++){
			//verde
			printf("\033[1;32m");
			printf ("\t|");
			printf("\033[0m");
			//celeste
			printf("\033[0;36m ");
			printf ("%c",tablero[i][j]);
			printf("\033[0m");
			//verde
			printf("\033[1;32m");
			printf ("|");
			printf("\033[0m");
			
		}
	}
}

void llenar_tablero (int tablero [8][8]){
	int i;
	int j;
	// Inicialmente el tablero se llena con guian bajo (95 en codigo ascii)
	for (i=0; i<8; i++){
		for(j=0; j<8; j++){
			tablero[i][j]= 95;
		}
	}
}

int validar_fila_columna(int tablero[8][8],int jugada) {
	int fila=7;
	//Evalua que las filas y columnas, ademas limita el tablero
	if (jugada > 7 || jugada < 0) {
		fila = -1;
	}
	else {
		while (fila >= 0) {
			if (tablero[fila][jugada] != 95) {
				fila--;
			}
			else { 
				break;
			}
		}
	}
	return fila; 
} 

int sorteo_partida_inicial(){
	int jugador;
	int i;
	//Sorteo para evaluar que jugador inicia la partida
	for (i=0; i<2; i++){
		jugador = rand()%2 + 1;
	}
	return jugador;
}

int evaluar_ganador(int fila, int jugada, int tablero[8][8], int ficha){
	int Ganador=0;
	
	//Ganar vertical
	if (tablero[fila][jugada]==ficha&&tablero[fila+1][jugada]==ficha&&tablero[fila+2][jugada]==ficha&&tablero[fila+3][jugada]==ficha){
		Ganador++;
	}
	//Ganar horizontal
	else if (tablero[fila][jugada]==ficha&&tablero[fila][jugada+1]==ficha&&tablero[fila][jugada+2]==ficha&&tablero[fila][jugada+3]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila][jugada-1]==ficha&&tablero[fila][jugada-2]==ficha&&tablero[fila][jugada-3]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila][jugada+1]==ficha&&tablero[fila][jugada-1]==ficha&&tablero[fila][jugada-2]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila][jugada-1]==ficha&&tablero[fila][jugada+1]==ficha&&tablero[fila][jugada+2]==ficha){
		Ganador++;
	}
	
	//Ganar diagonal
	else if (tablero[fila][jugada]==ficha&&tablero[fila-1][jugada-1]==ficha&&tablero[fila-2][jugada-2]==ficha&&tablero[fila-3][jugada-3]==ficha){
		Ganador++;
	}

	else if (tablero[fila][jugada]==ficha&&tablero[fila+1][jugada+1]==ficha&&tablero[fila+2][jugada+2]==ficha&&tablero[fila+3][jugada+3]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila-1][jugada+1]==ficha&&tablero[fila-2][jugada+2]==ficha&&tablero[fila-3][jugada+3]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila+1][jugada-1]==ficha&&tablero[fila+2][jugada-2]==ficha&&tablero[fila+3][jugada-3]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila+1][jugada-1]==ficha&&tablero[fila-1][jugada+1]==ficha&&tablero[fila-2][jugada+2]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila-1][jugada+1]==ficha&&tablero[fila+1][jugada-1]==ficha&&tablero[fila+2][jugada-2]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila-1][jugada-1]==ficha&&tablero[fila+1][jugada+1]==ficha&&tablero[fila+2][jugada+2]==ficha){
		Ganador++;
	}
	else if (tablero[fila][jugada]==ficha&&tablero[fila+1][jugada+1]==ficha&&tablero[fila-1][jugada-1]==ficha&&tablero[fila-2][jugada-2]==ficha){
		Ganador++;
	}	
	return Ganador;
}

int evalucion_empate (int tablero[8][8]){
	int i;
	int j;
	int empate=0;
	
	for (i=0; i<8; i++){
		for (j=0; j<8; j++){
			if (tablero[i][j]!=95){
				empate++;
			}
		}
	}	
	return empate;
}

int dos_player(int tablero [8][8], int jugador, char jugador1_nombre[10], char jugador2_nombre[10]) {
	//Juego persona contra persona
	int fila_valida;
	int jugada;
	int turno=jugador;
	int ganador;
	int empate;
	
	while(1||2) {
		//Condicion cuando el sorteo indica 1
		if (turno==1) {
			printf ("\n\n   Donde desea jugar, %s? ", jugador1_nombre);
			scanf("%d",&jugada);
			jugada--;
			fila_valida = validar_fila_columna(tablero, jugada);
			if (fila_valida != -1) {
				tablero[fila_valida][jugada] = ficha1;
				imprimir_tablero(tablero);
				ganador= evaluar_ganador(fila_valida,jugada,tablero, ficha1);
				if (ganador>0) {
					imprimir_tablero(tablero);
					sleep(1);
					printf ("\nGanador: %s", jugador1_nombre);
					break;
				}
				else {
					empate= evalucion_empate(tablero);
					if (empate == 64) {
						printf ("\n\n   EMPATE!");
						sleep(1);
						break;
					}
					else{
						turno=2;
				 }
				}
			}
			else {
				printf("\n\n  La posicion ingresada no es valida. Intenta nuevamente!");
				turno=1;
			}
		}
		//Condicion cuando el sorteo indica 2
		if (turno==2) {
			printf ("\n\n   Donde desea jugar, %s? ", jugador2_nombre);
			scanf("%d",&jugada);
			jugada--;
			fila_valida=validar_fila_columna(tablero, jugada);
			if (fila_valida != -1) {
				tablero[fila_valida][jugada] = ficha2;
				imprimir_tablero(tablero);
				ganador= evaluar_ganador(fila_valida,jugada,tablero, ficha2);
				if (ganador>0) {
					imprimir_tablero(tablero);
					sleep(1);
					printf ("\nGanador: %s", jugador2_nombre);
					break;
				}
				else {
					empate= evalucion_empate(tablero);
					if (empate == 64) {
						printf ("\n\n   EMPATE!");
						sleep(1);
						break;
					}
					else{
					turno=1;
					jugador++;
					}
				}
			}
			else {
				printf("\n\n  La posicion ingresada no es valida. Intenta nuevamente!");
				turno=2;
			}
		}
	}
	system ("clear");
	return jugada;
}
void un_player(int tablero[8][8], int jugador, char jugador1_nombre[10]){
//Juego contra el pc
	int fila_valida = 0;
	int jugada_columna;
	int turno=jugador;
	int ganador;
	int empate;
	
	while(1||2) {
		//Condicion cuando el sorteo indica 1
		if (turno==1) {
			if (fila_valida >= 0){
			imprimir_tablero(tablero);
			printf ("\n\n   Donde desea jugar, %s? ", jugador1_nombre);
			scanf ("%d", &jugada_columna);
			jugada_columna--;
			fila_valida = validar_fila_columna(tablero, jugada_columna);
				if (fila_valida != -1) {
					tablero[fila_valida][jugada_columna] = ficha1;
					ganador= evaluar_ganador(fila_valida,jugada_columna,tablero, ficha1);
					if (ganador>0) {
						imprimir_tablero(tablero);
						sleep(1);
						printf ("\nGanador: %s", jugador1_nombre);
						break;
					}
					else {
						empate= evalucion_empate(tablero);
						if (empate == 64) {
							printf ("\n\n   EMPATE!");
							sleep(1);
							break;
						}
						else{
						turno=2;
						}
					}
				}
			}
			else {
				printf("\n\n  La posicion ingresada no es valida. Intenta nuevamente!");
				turno=1;
			}
		}
		//Condicion cuando el sorteo indica 2
		if (turno==2) {
			jugada_columna = ((rand()%8)+1);
			jugada_columna--;
			fila_valida = validar_fila_columna(tablero, jugada_columna);
			tablero[fila_valida][jugada_columna] = ficha2;
			ganador = evaluar_ganador(fila_valida,jugada_columna,tablero, ficha2);
			if (ganador>0) {
				imprimir_tablero(tablero);
				sleep(1);
				printf ("\nGanador: Computador");
				break;
			}
			else {
				empate= evalucion_empate(tablero);
				if (empate == 64) {
					printf ("\n\n   EMPATE!");
					sleep(1);
					break;
				}
				else{
					turno=1;
				}
			}
		}
	}
	system ("clear");
}

void modo_de_juego (int opcion, int tablero[8][8], int jugador, char jugador1_nombre[10], char jugador2_nombre[10]){
	printf ("\n");
	//Condicion cuando el usuario incresa la opcion 1
	if (opcion ==1){
		printf ("   Juego v/s computador\n");
		if (jugador ==1){
			printf ("\n   %s juega con %c", jugador1_nombre,ficha1);
			printf ("\n   Computador juega con %c",ficha2);
			printf ("\n   La partida la inicia %s", jugador1_nombre);
		}
		else {
			printf ("\n   %s juega con %c", jugador1_nombre,ficha1);
			printf ("\n   Computador juega con %c",ficha2);
			printf ("\n   La partida la inicia el computador");
		}
		un_player(tablero, jugador, jugador1_nombre);
	}
	//Condicion cuando el usuario incresa la opcion 2
	else{
		printf ("Jugador v/s jugador\n");
		if (jugador ==1){
			printf ("\n   %s juega con %c", jugador1_nombre,ficha1);
			printf ("\n   %s juega con %c", jugador2_nombre,ficha2);
			printf ("\n   La partida la inicia %s", jugador1_nombre);
		}
		else{
			printf ("\n   %s juega con %c", jugador1_nombre,ficha1);
			printf ("\n   %s juega con %c", jugador2_nombre,ficha2);
			printf ("\n   La partida la inicia %s", jugador2_nombre);
		}
		imprimir_tablero(tablero);
		dos_player(tablero,jugador, jugador1_nombre, jugador2_nombre);	
	}
}
int main (void){
	srand(time(NULL));
	int tablero[8][8];
	int opcion=1;
	int jugador;
	char jugador1_nombre[10];
	char jugador2_nombre[10];
	
	printf ("\n\t\t___________________CUATRO EN LINEA___________________\n");
	
	while (opcion>0){
		printf ("\n\n   DESEA JUGAR?");
		printf ("\n\t[0] [Salir]\n\t[1] [1 PLAYER]\n\t[2] [2 PLAYER]\n\t[3] [INSTRUCCIONES]\n\n");
		printf ("\n\n\t- - - - - - - - - - ");
		printf ("\n\tIngrese su opcion ");
		printf ("\n\t- - - - - - - - - - \n\t : ");
		scanf ("%d", &opcion);
		printf ("\t_____________________________________________________________\n");
		
			switch (opcion){
				case 1: 
				//Modalidad 1: Jugador v/s PC
					llenar_tablero (tablero);
					printf ("\tIngrese el nombre del jugador 1: ");
					scanf ("%s",jugador1_nombre);
					getchar();
					jugador = sorteo_partida_inicial();
					modo_de_juego(opcion, tablero, jugador, jugador1_nombre, jugador2_nombre);
					break;
				case 2:
				//Modalidad 2: Jugador v/s jugador
					llenar_tablero (tablero);
					printf ("\tIngrese el nombre del jugador 1: ");
					scanf ("%s",jugador1_nombre);
					getchar();
					printf ("\tIngrese el nombre del jugador 2: ");
					scanf ("%s", jugador2_nombre);
					jugador = sorteo_partida_inicial();
					modo_de_juego(opcion, tablero, jugador, jugador1_nombre, jugador2_nombre);
					break;
				case 3:
				//Muestra las instrucciones del juego
					system ("clear");
					printf ("\nEl juego consta de dos opciones:"); 
					printf ("\n\n   [1] PLAYER 1: Indica un juego entre usuario y computador.");
					printf ("\n   [2] PLAYER 2: Indica un juego entre dos usuarios.");
					printf ("\n\nPara jugar, según la opcion elegida, debe ingresar específicamente un numero,");
					printf ("\nno caracteres, el cual representará la columna en la que desea posicionar su ficha.");
					break;
				case 0:
				//Salida del juego
					printf ("El juego ha terminado C:");
					break;
					
				default:
				//Se utiliza cuando el usuario ingresa una opcion incorrecta
					printf("Opción inválida!. Intenta nuevamente.\n");
					break;
		}
	}
	return 0;
}
