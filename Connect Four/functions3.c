#include <limits.h>
#include <string.h>

char matrix[6][7];
int moves[42]; 
int counter = 0;
int w = 0;

// //Print the board
void PrintBoard(){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			printf("|");
			printf("%c", matrix[i][j]);
			if(j == 6){
				printf("|\n");
			}
		}
	}
	printf(" 1 2 3 4 5 6 7\n");
}

//Put in the board 
void PutInMatrix(int* column, char player){
		if(*column <= 7 && *column >= 0){
			if(*column != 0){
				moves[counter] = *column;
				counter = counter + 1;
				for(int i = 5; i >= 0; i--){
					if(matrix[i][*column -1] == ' '){
						matrix[i][*column -1] = player;
						break;

					}
				}
			}
			else {
				for(int i = 0; i <= 5; i++){
					if(matrix[i][moves[counter -1] -1] != ' '){
						matrix[i][moves[counter -1] -1] = ' ';
						break;
					}
				}
				counter--;
			}
		}
		PrintBoard();
}

//Count by line
int goLine(char player){
	for(int i = 5 ; i >= 0; i--){
		for(int j = 0; j <= 6; j++){
			if(matrix[i][j] == player){
                while(j+1 <= 6 && matrix[i][j+1] == player && w < 3){
                    w++;
					j++;
				}
			}
			if(w == 3){
				w = 0;
				return 1;
				break;
			}
			w = 0;
		}
	}
	return 0;
}

//Count by column
int goColumn(char player){
	 for(int i = 5 ; i >= 0; i--){
		for(int j = 0; j <= 6; j++){
			if(matrix[i][j] == player){
				while(i-1 >= 0 && matrix[i-1][j] == player && w < 3){
					w++;
					i--;
				}
			}
			if(w == 3){
				w = 0;
				return 1;
				break;
			}
			w = 0;
		}
	}
	return 0;
}

//Count to right & up
int rightUp(char player){
	 for(int i = 5 ; i >= 0; i--){
		for(int j = 0; j <= 6; j++){
			if(matrix[i][j] == player){
				while(i-1 >= 0 && j+1 <= 6 && matrix[i-1][j+1] == player && w < 3){
					w++;
					i--;
					j++;
				}
			}
			if(w == 3){
				w = 0;
				return 1;
				break;
			}
			w = 0;
		}
	}
	return 0;
}

//Count to left & up
int leftUp(char player){
	 for(int i = 5 ; i >= 0; i--){
		for(int j = 0; j <= 6; j++){
			if(matrix[i][j] == player){
				while(i-1 >= 0 && j-1 >= 0 && matrix[i-1][j-1] == player && w < 3){
					w++;
					i--;
					j--;
				}
			}
			if(w == 3){
				w = 0;
				return 1;
				break;
			}
			w = 0;
		}
	}
	return 0;
}

//Check if player wins.
int isWinner(char player){
	if(goLine(player) == 1 || goColumn(player) == 1 || rightUp(player) == 1 || leftUp(player) == 1){
  		printf("Player %c wins!\n", player);
		return 1;
	}			  
	return 0;
}

//Check if it's a tie
int isTie (){
	if(counter == 42){
		printf("It's a tie!\n");
		return 1;
	}
	return 0;
}