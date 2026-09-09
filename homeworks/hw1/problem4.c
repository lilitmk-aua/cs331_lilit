#include <stdio.h>

int main(){
    int a = 1;
    int* p = &a;
    int **pp = &p;

    printf("number a: %d\n",a);
    printf("number a using the pointer: %d\n", *p);
    printf("number a using the pointer of the pointer: %d\n", **pp);

    return 0;
}