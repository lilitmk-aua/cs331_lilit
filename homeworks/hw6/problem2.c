#include <stdio.h>


struct Str{
    
    char a;
    int b;
    double c;
    
};

int main(){

    struct Str str;

    printf("Size of the struct: %d \n", (int)sizeof(struct Str));


    printf("Address of a: %p \n", &str.a);
    printf("Address of b: %p \n", &str.b);
    printf("Address of c: %p \n", &str.c);



}