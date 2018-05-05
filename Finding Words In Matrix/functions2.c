#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int bool;
#define true 1
#define false 0

 #define MATRIX_SIZE 4
char A[MATRIX_SIZE][MATRIX_SIZE]= {'C','A','R','T','E','T','A','K','E','S','M','E','L','L','P','N'};
bool visited[MATRIX_SIZE][MATRIX_SIZE];

//Check if the string is a word.
bool isWord(char* s){
    return (!strcmp(s,"CAT") | !strcmp(s,"CATS") |!strcmp(s,"TRAMP") |
            !strcmp(s,"TRAM") | !strcmp(s,"TRAMS") |!strcmp(s,"TAME") | !strcmp(s,"CAR") |
            !strcmp(s,"CARS") | !strcmp(s,"RAT") |!strcmp(s,"RATS") | !strcmp(s,"RAMP") |
            !strcmp(s,"ART") | !strcmp(s,"CART") |!strcmp(s,"STAMP") | !strcmp(s,"TAKEN") |
            !strcmp(s,"MEN") | !strcmp(s,"MAKE") |!strcmp(s,"TAKE") | !strcmp(s,"ATE") |
            !strcmp(s,"SELL") | !strcmp(s,"STEEL") |!strcmp(s,"RAKE")| !strcmp(s,"STAR")|
            !strcmp(s,"START")| !strcmp(s,"STAKE")|!strcmp(s,"LEE")| !strcmp(s,"RATE"));
} 

// // Print the words and count them
int NumOfWords(char s[ ], int* count){
    char w[30][MATRIX_SIZE*MATRIX_SIZE+1];
    if (isWord(s)){
        for(int k =0; k<30; k++){
            if(strcmp(s, w[k]) == 0){
                break;
            }
            else{ 
                if(strcmp(w[k], "") == 0){
                    *count++;
                    strcpy(w[k] ,s); 
                    printf("%s\n", w[k]);     
                    k = 30;
                    break;              
                }
            }
        }
    }
    return *count;
}

//Recursive function that prints all words presented on A.
int findWords(int i, int j, char word [], int* count){
    
    NumOfWords(word, count);
    
    if(i-1>=0 && visited[i-1][j]==false){//go up
        int length= strlen(word);
        word[length]=A[i-1][j];
        word[length+1]='\0';
        visited[i-1][j]=true;
        findWords(i-1,j, word, count);
        word[length]='\0';   
    }

    if(i+1<MATRIX_SIZE && visited[i+1][j]==false){//go down
        int length= strlen(word);
        word[length]=A[i+1][j];
        word[length+1]='\0';
        visited[i+1][j]=true;
        findWords(i+1,j, word, count);
        word[length]='\0';   
    }

    if(j-1>=0 && visited[i][j-1]==false){//go left
        int length= strlen(word);
        word[length]=A[i][j-1];
        word[length+1]='\0';
        visited[i][j-1]=true;
        findWords(i,j-1, word, count);
        word[length]='\0';   
    }

    if(j+1<MATRIX_SIZE && visited[i][j+1]==false){//go right 
        int length= strlen(word);
        word[length]=A[i][j+1];
        word[length+1]='\0';
        visited[i][j+1]=true;
        findWords(i,j+1, word, count);
        word[length]='\0';   
    }

    visited[i][j] = false;
    

    return *count;
}

 //Print the words and return the number of them.
 int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]){
    int countWords;
    bool visited[MATRIX_SIZE][MATRIX_SIZE] = {{false}};
    char word[16];
    
    //Consider every character and look for all words starting with this character
    for (int i = 0; i < MATRIX_SIZE; i++){
        for(int j = 0; j < MATRIX_SIZE; j++){
            word[0]=A[i][j];
            word[1]='\0';   
            visited[i][j]=true;  
            findWords(i, j, word, &countWords);             
        }
    }

    //printf("Number of words: %d", countWords);

    return countWords;
}


 


