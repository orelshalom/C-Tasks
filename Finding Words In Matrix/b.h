typedef int bool;
#define true 1
#define false 0
#define MATRIX_SIZE 4

bool isWord(char* s);
int NumOfWords(char s [], int* count);
int printWords(char A[MATRIX_SIZE][MATRIX_SIZE]);
int findWords(int i, int j, char word [], int* count);
    