#include <stdio.h>


int main(){


    int i;
    char c;
    double d;
    short s;


    printf("Size of int: %d \n", (int)sizeof(int));
    printf("Size of char: %d \n", (int)sizeof(char));
    printf("Size of double: %d \n", (int)sizeof(double));
    printf("Size of short: %d \n", (int)sizeof(short));


    printf("Address of i: %p \n", &i);
    printf("Address of c: %p \n", &c);
    printf("Address of d: %p \n", &d);
    printf("Address of s: %p \n", &s);


}