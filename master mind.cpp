// De Molli Christian
// Realizzare il programma master mind

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

#define RIGHE 10
#define COLONNE 4
#define DIM 4
#define MIN 1
#define MAX 6
#define NMOSSE 10

int main()
{
	int numero;
	int scelta;
	int cont = 0;
	char stringa[DIM];
	char matrice_1[RIGHE][COLONNE];
	char matrice_2[RIGHE][COLONNE];
	bool uscita = false;
	bool haivinto = false;
	bool exit = false;

	std::cout << R"(



                                /              &&                               
                              &&&             &&&&&@                            
                            &&&&&&         @&&&&&&&&&                           
                           &&&&&&&&     /&&&&&&&&&&&&&                          
                          (&&&&&&&&&&   &    &&&&&&&&&@                         
                          /&&&&&&&&&&&&@      &&&&&&&&&                         
                           &&&&&&&&&&&&&&      &&&&&&&                          
                            &&&&&&&&&&&&&&     &&&&&&                           
                             /&&&&&&&&&&&@    @&&&&                             
                                &&&&&&&&&   &&&&                                
                                @&&&&&@                                         
                              &&&&&@                                            
                             &&&&                                               
                            ,&&                                                 
                             &    
															)";
	printf("\n\n");
	Sleep(3000); 
	system("cls");

	do
	{
		printf("1) START\n");
		printf("2) EXIT\n");
		printf("> ");
		scanf_s("%d", &scelta);
		printf("\n");

		switch (scelta)
		{
		case 1:			
			haivinto = false;
			cont = 0;

			for (int i = 0; i < RIGHE; i++) {
				for (int j = 0; j < COLONNE; j++) {
					matrice_1[i][j] = '0';
				}
			}

			for (int i = 0; i < RIGHE; i++) {
				for (int j = 0; j < COLONNE; j++) {
					matrice_2[i][j] = '0';
				}
			}


			for (int i = 0; i < DIM; i++) {
				numero = rand() % (MAX - MIN + 1) + MIN;
				switch (numero)
				{
				case 1:
					stringa[i] = 'A';
					break;
				case 2:
					stringa[i] = 'B';
					break;
				case 3:
					stringa[i] = 'R';
					break;
				case 4:
					stringa[i] = 'G';
					break;
				case 5:
					stringa[i] = 'M';
					break;
				case 6:
					stringa[i] = 'V';
				}
			}

			for (int i = 0; i < NMOSSE; i++) {
				if (cont >= 4) {
					break;
				}
				for (int j = 0; j < COLONNE; j++) {
					do {
						printf("\nI colori disponibili sono: ");
						SetConsoleTextAttribute(hCon, 11); 
						printf("A "); 
						SetConsoleTextAttribute(hCon, 9); 
						printf("B "); 
						SetConsoleTextAttribute(hCon, 12);
						printf("R "); 
						SetConsoleTextAttribute(hCon, 14); 
						printf("G "); 
						SetConsoleTextAttribute(hCon, 13); 
						printf("M "); 
						SetConsoleTextAttribute(hCon, 10);
						printf("V \n\n"); 
						SetConsoleTextAttribute(hCon, 15);

						printf("Inserire il colore > ");
						scanf_s(" %c", &matrice_1[RIGHE - i - 1][j]);

						printf("\n");

						switch (matrice_1[RIGHE - i - 1][j]) {
						case 'A':
						case 'B':
						case 'R':
						case 'G':
						case 'M':
						case 'V':
							exit = true;
							break;
						default:
							break;
						}
					} while (exit == false);

					if (matrice_1[RIGHE - i - 1][j] == stringa[j]) {
						matrice_2[RIGHE - i - 1][j] = 'B';
					}
					else {
						matrice_2[RIGHE - i - 1][j] = 'N';
					}

					system("cls"); 
					printf("\n"); 

					for (int p = 0; p < RIGHE; p++) {
						for (int l = 0; l < COLONNE; l++) {
							if (matrice_2[p][l] == 'B') {
								SetConsoleTextAttribute(hCon, 10);
							}
							if (matrice_2[p][l] == 'N') {
								SetConsoleTextAttribute(hCon, 12);
							}
							if (matrice_2[p][l] != 'B' && matrice_2[p][l] != 'N') {
								SetConsoleTextAttribute(hCon, 15);
							}
							printf(" %c\t", matrice_2[p][l]);
						}
						printf("\t");
						SetConsoleTextAttribute(hCon, 15);
						for (int l = 0; l < COLONNE; l++) {
							printf(" %c\t", matrice_1[p][l]); 
						}
						printf("\n");
					}
					SetConsoleTextAttribute(hCon, 15);
				}

				for (int p = 0; p < COLONNE; p++) {
					if (matrice_2[RIGHE - i - 1][p] == 'B') {
						cont++;
					}
				}
				if (cont >= 4) {
					break;
				}
				else {
					cont = 0;
				}
			}

			printf("\n");

			if (cont >= 4) {
				SetConsoleTextAttribute(hCon, 14);
				printf("Complimenti hai vinto!\n");
				SetConsoleTextAttribute(hCon, 15);
			}
			else {
				SetConsoleTextAttribute(hCon, 14);
				printf("Hai perso!\n");
				SetConsoleTextAttribute(hCon, 15);
			}
			Sleep(5000);
			system("cls");
			break;
		case 2:
			uscita = true;
			break;
		}
	} while (uscita == false);

	system("pause");
	return 0;
}