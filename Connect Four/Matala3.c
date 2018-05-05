#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "functions3.c"
#include "c.h"

int winner = 0;
int turn = 1;
char term;
int column = 0;
char matrix[6][7] = {{' ',' ',' ',' ',' ',' ',' '},
					 {' ',' ',' ',' ',' ',' ',' '},
					 {' ',' ',' ',' ',' ',' ',' '},
					 {' ',' ',' ',' ',' ',' ',' '},
					 {' ',' ',' ',' ',' ',' ',' '},
					 {' ',' ',' ',' ',' ',' ',' '}};

int main(){

	printf("\nWelcome!\n\n");
	PrintBoard();

	while (winner == 0){
		if (turn == 1){
			if(isWinner('O') == 1 || isTie() == 1){
				winner = 1;
				break;
			}
			else{
				printf("Player X, please enter a column number (or 0 to undo): ");
				if(scanf("%d%c", &column, &term) != 2 || term != '\n'){
					if(column <= 7 && column > 0){
						PutInMatrix(&column,'X');
						printf("Invalid input, bye-bye!\n");
						winner = 3;
						break;
					}
					else {
						if (column == 0){
							PutInMatrix(&column,'X');
							printf("Invalid input, bye-bye!\n");
							winner = 3;
							break;
						}
						else{
							printf("Invalid input, bye-bye!\n");
							winner = 3;
							break;
						}
					}
				}
				else {
					while(column == 0 && matrix[5][0] == ' ' && matrix[5][1] == ' ' && matrix[5][2] == ' ' && matrix[5][3] == ' ' && matrix[5][4] == ' ' && matrix[5][5] == ' ' && matrix[5][6] == ' '){
						printf("Board is empty - can't undo!\n");
						printf("Invalid input, the number must be between 1 to 7: " );
						scanf("%d;\n", &column);
						PutInMatrix(&column,'X');
					}
					while(column > 7 || column < 0){
						printf("Invalid input, the number must be between 1 to 7: " );
						scanf("%d;\n", &column);
						PutInMatrix(&column,'X');
					}
					while(matrix[0][column -1] != ' ' && column != 0){
						printf("Invalid input, this column is full. Please choose another one: ");
						scanf("%d;\n", &column);
						PutInMatrix(&column,'X');
					}
					PutInMatrix(&column,'X');
				}
			}
			turn = 2;
		}

		else{ 
			if (turn == 2){
				if(isWinner('X') == 1 || isTie() == 1){
					winner = 1;
					break;
				}
				else {
					printf("Player O, please enter a column number (or 0 to undo): ");
					if(scanf("%d%c", &column, &term) != 2 || term != '\n'){
						if(column <= 7 && column > 0){
							PutInMatrix(&column,'O');
							printf("Invalid input, bye-bye!\n");
							winner = 3;
							break;
						}
						else {
							if (column == 0){
								PutInMatrix(&column,'O');
								printf("Invalid input, bye-bye!\n");
								winner = 3;
								break;
							}
							else{
								printf("Invalid input, bye-bye!\n");
								winner = 3;
								break;
							}
						}
					}
					else {
						while(column == 0 && matrix[5][0] == ' ' && matrix[5][1] == ' ' && matrix[5][2] == ' ' && matrix[5][3] == ' ' && matrix[5][4] == ' ' && matrix[5][5] == ' ' && matrix[5][6] == ' '){
							printf("Board is empty - can't undo!\n");
							printf("Invalid input, the number must be between 1 to 7: " );
							scanf("%d;\n", &column);
							PutInMatrix(&column,'O');
						}
						while(column > 7 || column < 0){
							printf("Invalid input, the number must be between 1 to 7: " );
							scanf("%d;\n", &column);
							PutInMatrix(&column,'O');
						}
						while(matrix[0][column -1] != ' ' && column != 0){
							printf("Invalid input, this column is full. Please choose another one: ");
							scanf("%d;\n", &column);
							PutInMatrix(&column,'O');
						}
						PutInMatrix(&column,'O');
					}
				}
				turn = 1;
			}
		}
	}
	return 0;
}

