#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<string.h>
#include <stdbool.h>

int num;
int i = 0;
int j = 0;
int k = 0;

typedef struct node {
    int val;
    struct node * next;
} node_t;

struct Stack{
    int top;
    unsigned capacity;
    int* array;
};

void push(node_t *head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}
 
void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

int setValue(node_t * head ,int val, int index){
    node_t * current = head;
    for(int g = 0; g <= index; g++){
        if(g == index)
            current->val = val;
        else current = current->next;
    }
    return current->val;
}

int returnVal(node_t * head, int index){
    node_t * current = head;
    for(int g = 0; g <= index; g++){
        if(g == index)
            return current->val;
        else current = current->next;    
    }
    return -1;
}

void merge(node_t * head, int start, int mid, int end){
    int a, b, c;
    int n1 = mid - start + 1;
    int n2 =  end - mid;
    node_t * Left = malloc(sizeof(node_t));
    node_t * Right = malloc(sizeof(node_t));    
    node_t * current = head;

    
    for (a = 0; a < n1; a++){
        if (a == 0){
            setValue(Left, returnVal(current, start + a), a);
        }
        else{
            push(Left, returnVal(current, start + a));
        }
    }
    for (b = 0; b < n2; b++){
        if (b == 0){
            setValue(Right, returnVal(current, mid + 1 + b), b);
        }
        else{
            push(Right, returnVal(current, mid + 1 + b));
        } 
    }
 
    a = 0; 
    b = 0; 
    c = start;
    while (a < n1 && b < n2){
        if (returnVal(Left, a) <= returnVal(Right, b)){
            setValue(current, returnVal(Left, a), c);
            a++;
        }
        else{
            setValue(current, returnVal(Right, b), c);
            b++;
        }
        c++;
    }
    while (a < n1){
        setValue(current, returnVal(Left, a), c);
        a++;
        c++;
    }
    current = head;
    while (b < n2){
        setValue(current, returnVal(Right, b), c);
        b++;
        c++;
    }
}

void mergeSort(node_t * head, int start, int end){
    if (start < end){
        int mid = start+(end-start)/2;
        mergeSort(head, start, mid);
        mergeSort(head, mid+1, end);
        merge(head, start, mid, end);
    }
}
 
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(struct Stack* stack){   
    return stack->top == -1;  
}
 
void pushToStack(struct Stack* stack, char item){
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%c pushed to stack\n", item);
}
 
int pop(struct Stack* stack){
    if (isEmpty(stack))
        return INT_MIN;
    printf("%c poped from stack\n", stack->array[stack->top]);
    return stack->array[stack->top--];
}

int isFit(struct Stack* stack, char bracket){
    return stack->array[stack->top] == bracket; 
}

char peek(struct Stack* stack){
    if (isEmpty(stack))
        return '0';
    return stack->array[stack->top];
}

bool isStringBalanced(char** sentence, int size){
    size = strlen(*sentence);
    printf("%s\n",*sentence);
    struct Stack* stack = createStack(size);
    
    for(int i = 0; i<size; i++){
        if((*sentence)[i] == '(' || (*sentence)[i] == '[' || (*sentence)[i] == '{'){
            pushToStack(stack, (*sentence)[i]);
        }
        else{ 
            if((*sentence)[i] == ')' || (*sentence)[i] == ']' || (*sentence)[i] == '}'){
                if(((*sentence)[i] == ')' && isFit(stack, '(')) || ((*sentence)[i] == ']' && isFit(stack, '[')) || ((*sentence)[i] == '}' && isFit(stack, '{'))){
                    pop(stack);
                }
            }
        }
    }
    if(isEmpty(stack)){
        printf("Top element is %c\n", peek(stack));
        printf("String is balanced!\n");
        return true;
    }
    else{
        printf("Top element is %c\n", peek(stack));
        printf("String is not balanced!\n");
        return false;
    }
    return false;
}