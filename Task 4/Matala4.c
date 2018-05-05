#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
#include "functions4.c"
#include "d.h"

int num;
int once = 0;
int size = 0;
int times;
node_t * head;
node_t * head2;
char sentence[] = "if (x[i] > x[j) { return;}";
char * arr = sentence;


int take(int num){
    int mid;
    if (once == 0){
        head = malloc(sizeof(node_t));
        if (head == NULL)
            return 1;
        head->val = num;
        head->next = NULL;
        size++;
        once++;
        printf("The num in the mid of the array: %d\n\n", head->val);
        return head->val;
    }

    push(head, num);
    size++;
    mid = (size)/2;
    print_list(head);
        
    node_t * current = head;
    for(int i = 0; i < mid; i++){
        current = current->next;
    }
    printf("The num in the mid of the array: %d\n\n", current->val);
    return current->val; 
}
   
int take2(int num){
    if (once == 0){
        head2 = malloc(sizeof(node_t));
        if (head2 == NULL)
            return 1;
        head2->val = num;
        head2->next = NULL;
        size = 0;
        size++;
        once++;
        print_list(head2);
        printf("The median number: %d\n\n", head2->val);
        return head2->val;
    }
    
    push(head2, num);
    size++;
    print_list(head2);
    mergeSort(head2, 0, size-1);
    print_list(head2);
    int mid = size/2;
    printf("The median number: %d\n\n", returnVal(head2, mid));

    return returnVal(head2, mid);
}

int main(){
    printf("Enter number of times to run function take(): ");
    scanf("%d;", &times);
   
    for(int i = 0; i < times; i++){
        printf("Enter Number: ");
        scanf("%d;", &num);
        take(num);
    }

    once = 0;
    printf("Enter number of times to run function take2(): ");
    scanf("%d;", &times);
 
    for(int i = 0; i < times; i++){
        printf("Enter Number: ");
        scanf("%d;", &num);
        take2(num);
    } 

    isStringBalanced(&arr,size);

    return 0;
}

