#include<stdio.h>
#include<stdlib.h>

typedef struct myClass{
    int m_x;
    void (*pAdd)();
} myClass_t;

typedef struct derived{
    myClass_t * class1;
} derived_t;

typedef struct derived2{
    myClass_t * class2;
    int m_y;
} derived2_t;

myClass_t * class;
derived_t * derived;
derived2_t * derived2;

void add(myClass_t * class, int y){
    class->m_x = class->m_x + y;
}

void xor(derived_t * derived, int y){
    derived->class1->m_x = derived->class1->m_x^y;
}

void add2(derived2_t * derived2, int y){
    derived2->class2->m_x = derived2->class2->m_x + y;
    derived2->m_y = y;
}

int main(){

    printf("myClass info: \n");
    class = malloc(sizeof(myClass_t));
    class->pAdd = add;
    class->m_x = 10;
    printf("Before: %d \n", class->m_x);
    class->pAdd(class, 6);
    printf("After: %d \n\n", class->m_x);

    printf("Derived info: \n");
    derived = malloc(sizeof(derived_t));
    derived->class1 = malloc(sizeof(myClass_t));
    derived->class1->pAdd = xor;
    derived->class1->m_x = 12;
    printf("Before: %d \n", derived->class1->m_x);
    derived->class1->pAdd(derived, 25);
    printf("After: %d \n\n", derived->class1->m_x);
    
    printf("Derived2 info: \n");
    derived2 = malloc(sizeof(derived2_t));
    derived2->class2 = malloc(sizeof(myClass_t));
    derived2->class2->pAdd = &add2;
    derived2->class2->m_x = 12;
    printf("Before: %d \n", derived2->class2->m_x);
    derived2->class2->pAdd(derived2, 25);
    printf("After: %d \n", derived2->class2->m_x);
    printf("int m_y: %d \n", derived2->m_y);


    return 0;
}