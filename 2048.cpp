//De Molli Christian

// tramite menu: realizzare il gioco 2048 in questo gioco, si ha una matrice quadrata 5X5, in cui ad inizio partita vengono inseriti 3 valori in posizioni casuali. 
// Il giocatore decide ogni turno 1 delle 4 direzioni(usando le frecce), tutti i valori si spostano verso quella direzione, dopo il turno dell'utente viene generato 
// in una pos. casuale un numero.

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);   

#define RIGHE 4
#define COLONNE 4

#define MAX 3
#define MIN 0

void Azzera(int mat[][COLONNE]); // ok

void Genera(int mat[][COLONNE]);  // ok

void StampaMat(int mat[][COLONNE]); // ok

void ShiftAlto(int mat[][COLONNE]); // forse ok
void ShiftBasso(int mat[][COLONNE]); // forse ok
void ShiftDestra(int mat[][COLONNE]); // forse ok
void ShiftSinistra(int mat[][COLONNE]); // forse ok

bool ControlloPiena(int mat[][COLONNE]); 
bool ControlloVittoria(int mat[][COLONNE]);

void StampaVittoria(bool vittoria);
void StampaSconfitta(bool piena);  

void  Menu(int mat[][COLONNE]);

int main()
{
	srand(time_t(NULL)); 
	int mat[RIGHE][COLONNE];
	Menu(mat);
	return 0;
}


void Azzera(int mat[][COLONNE]) {
	for (int i = 0; i < RIGHE; i++) {
		for (int j = 0; j < COLONNE; j++) {
			mat[i][j] = 0;
		}
	}
}

void Genera(int mat[][COLONNE]) {
	int riga;
	int colonna;

	do {
		riga = rand() % (MAX - MIN + 1) + MIN;
		colonna = rand() % (MAX - MIN + 1) + MIN;
	} while (mat[riga][colonna] != 0);
	mat[riga][colonna] = 2;
}

void StampaMat(int mat[][COLONNE]) {
	printf("\n -----------------\n");
	for (int i = 0; i < RIGHE; i++) {
		printf(" | ");
		for (int j = 0; j < COLONNE; j++) {
			printf("%d | ", mat[i][j]);
		}
		printf("\n -----------------\n");
	}
	printf("\n"); 
}


void ShiftAlto(int mat[][COLONNE]) {
	for (int i = 1; i < RIGHE; i++) {
		for (int j = 0; j < COLONNE; j++) {
			if ((mat[i][j] != 0 && mat[i - 1][j] != 0) && (mat[i][j] == mat[i - 1][j])) {
				mat[i - 1][j] *= 2;
				mat[i][j] = 0;
			}
			if (mat[i][j] != 0 && mat[i - 1][j] == 0) { 
				mat[i - 1][j] = mat[i][j]; 
				mat[i][j] = 0; 
			}
		}
	}
}

void ShiftBasso(int mat[][COLONNE]) {
	for (int i = RIGHE - 1; i >= 0; i--) {
		for (int j = 0; j < COLONNE; j++) {
			if ((mat[i][j] != 0 && mat[i + 1][j] != 0) && (mat[i][j] == mat[i + 1][j])) {
				mat[i + 1][j] *= 2;
				mat[i][j] = 0;
			}
			if (mat[i][j] != 0 && mat[i + 1][j] == 0) {
				mat[i + 1][j] = mat[i][j];
				mat[i][j] = 0;
			}
		}
	}
}

void ShiftSinistra(int mat[][COLONNE]) {
	for (int i = 0; i < RIGHE; i++) {
		for (int j = 1; j < COLONNE; j++) { 
			if ((mat[i][j] != 0 && mat[i][j - 1] != 0) && (mat[i][j] == mat[i][j - 1])) {
				mat[i][j - 1] *= 2;
				mat[i][j] = 0;
			}
			if (mat[i][j] != 0 && mat[i][j - 1] == 0) { 
				mat[i][j - 1] = mat[i][j];
				mat[i][j] = 0;
			}
		}
	}
}

void ShiftDestra(int mat[][COLONNE]) {
	for (int i = 0; i < RIGHE; i++) {
		for (int j = COLONNE - 2; j >= 0; j--) {
			if (mat[i][j] != 0 && mat[i][j + 1] == mat[i][j]) {
				mat[i][j + 1] *= 2;
				mat[i][j] = 0;
			}
			if (mat[i][j] != 0 && mat[i][j + 1] == 0) {
				mat[i][j + 1] = mat[i][j]; 
				mat[i][j] = 0; 
			}
		}
	}
}

bool ControlloPiena(int mat[][COLONNE]) {
	for (int i = 0; i < RIGHE; i++) { 
		for (int j = 0; j < COLONNE; j++) {
			if (mat[i][j] == 0) {
				return false;
			}
		}
	}
	return true;

}

bool ControlloVittoria(int mat[][COLONNE]) {
	for (int i = 0; i < RIGHE; i++) { 
		for (int j = 0; j < COLONNE; j++) {
			if (mat[i][j] == 2048) {
				return true;;
			}
		}
	}
	return false;
}

void StampaVittoria(bool vittoria) {
	if (vittoria == true) {
		system("cls\n"); 
		printf("Complimenti hai raggiunto 2048!\n\n");
		system("pause"); 
		system("cls\n");  
	}
}

void StampaSconfitta(bool piena) { 
	if (piena == true) { 
		system("cls\n"); 
		printf("Hai perso...c'eri quasi!\n\n");
		system("pause");  
		system("cls\n"); 
	}
}

void  Menu(int mat[][COLONNE]) {
	int scelta;
	bool uscita = false;
	char spostamento = ' ';
	bool vittoria = false; 
	bool primo_giro = true;
	bool piena = false;

	do {
		SetConsoleTextAttribute(hCon, 15); 
		
		printf("1) START\n");
		printf("2) EXIT\n> ");
		scanf_s("%d", &scelta);

		system("cls");

		primo_giro = true;

		switch (scelta) {
		case 1:
			Azzera(mat);
			do {
				if (primo_giro == true) {
					Genera(mat);
					primo_giro = false; 
					printf("PER SPOSTARSI UTILIZZARE I SEGUENTI TASTI:\n\n");
					SetConsoleTextAttribute(hCon, 14); 
					printf("A(sinistra) - W(alto) - S(basso) - D(destra)\n\n"); 
					SetConsoleTextAttribute(hCon, 15); 
					system("pause");
					system("cls");
				}
				Genera(mat); 
				StampaMat(mat);
				printf("> ");
				SetConsoleTextAttribute(hCon, 11); 
				scanf_s(" %c", &spostamento);
				SetConsoleTextAttribute(hCon, 15); 
				system("cls");

				switch (spostamento) {
				case 'A':
					ShiftSinistra(mat);
					break;
				case 'W':
					ShiftAlto(mat);
					break;
				case 'S':
					ShiftBasso(mat);
					break;
				case 'D':
					ShiftDestra(mat);
					break;
				}
				
				vittoria = ControlloVittoria(mat); 
				piena = ControlloPiena(mat); 

			} while (vittoria == false && piena == false); 

			StampaVittoria(vittoria); 
			StampaSconfitta(piena);

			break;
		case 2:
			uscita = true;
			break;
		}
	} while (uscita == false);
}