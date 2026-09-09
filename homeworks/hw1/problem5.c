#include <stdio.h>

int main(){
    char str[] = "Hello";
    char *p = str;
    
    for(int i = 0; i < 5; i++){
        printf("%c\n", *(p+i));
    }

    int c = 0;
    while(*p++) c++;
    printf("%d\n", c);

    return 0;
}