#include <stdio.h>

void swap(int *a, int *b){
    *a = *a+(*b);
    *b = *a -(*b);
    *a = *a -(*b);
}

int main(){
    int a = 4;
    int b = 7;


    printf("before the swap \n");
    printf("number a: %d\n",a);
    printf("number b: %d\n",b);

    swap(&a, &b);
    
    printf("after the swap \n");
    printf("number a: %d\n",a);
    printf("number b: %d\n",b);
    
    return 0;
}