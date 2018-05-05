#include <stdio.h>
#include "a.h"
#include "functions.c"

int main (){
    
        //Get 3 numbers
        int x, y, z;
        printf ("Enter three numbers: \n");
        scanf ("%d %d %d; ", &x, &y, &z);
    
        //Ordering the packets 
        Order (&x, &y, &z);
        printf ("Packets sizes are:\n%d %d %d \n", x, y, z);
    
        //First conditions
        int loser = 0;
        if (IsLoser(&x, &y, &z, &loser) == 1){
            printf ("Game Over - You Lost !!");
        }
        else {
            if(IsWinner(&x, &y, &z, &loser) == 1){
                printf ("You Won !!");
            }
        }
        
        //Continue playing
        int turn = 1;
        int first = 0;    
        while(loser == 0){
            //User's turn
            if (turn == 1){
                    if(IsWinner(&x, &y, &z, &loser) == 1){
                        printf ("You Won !!");
                        continue;
                    }
                    else{
                    if (((x + y == z && x != y) || (x == 1 && y == 1  && z == 2)) && first == 0){
                        printf ("Your Turn, please state how much to take: \n");
                        int a, b;
                        scanf ("%d to %d", &a, &b);
                        UserChoice (&a, &b, &x, &y, &z);
                        Order (&x, &y, &z);
                        printf ("Packets sizes are now:\n%d %d %d\n", x, y, z);
                        first = 1;
                    }
                    else {
                        if (first == 1){
                            printf ("Your Turn, please state how much to take: \n");
                            int a, b;
                            scanf ("%d to %d", &a, &b);
                            UserChoice (&a, &b, &x, &y, &z);
                            Order (&x, &y, &z);
                            printf ("Packets sizes are now:\n%d %d %d\n", x, y, z);
                        }
                    }
                }
                turn = 2;
            }
            //Computer's turn 
            if (turn == 2) {
                if(IsLoser(&x, &y, &z, &loser) == 1){
                    printf ("Game Over - You Lost !!");
                    continue;
                }
                    else {
                        if(IsWinner(&x, &y, &z, &loser) == 1){
                            printf ("You Won !!");
                            continue;
                        }
                
                        else {
                            if((x + y == z && x == y) || (x == 1 && y == 2 && z == 2)){
                                printf ("I turned %d to 0\n", z);
                                z = 0;
                                Order (&x, &y, &z);
                                printf ("Packets sizes are now:\n%d %d %d\n", x, y, z);
                                turn = 1;
                                continue;
                            }         
                            else {
                                    printf ("I turned %d to %d\n", z, y - x);
                                    z = y - x;
                                    Order (&x, &y, &z);
                                    printf ("Packets sizes are now:\n%d %d %d\n", x, y, z);
                                    turn = 1;
                            }
                        }
                    }
                }
              
            }
        
      return 0;
    }    