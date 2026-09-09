#include <stdio.h>

int main(){
    int a = 1;
    int* p = &a;

    printf("number a: %d\n",a);
    printf("address of a: %p\n",&a);
    printf("address of a using the pointer: %p\n",p);

    *p = *p + 1;
    printf("modified value of a using the pointer: %d\n",a);

    return 0;

}