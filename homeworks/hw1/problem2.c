#include <stdio.h>

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    int* p = a;


    printf("initial array \n");
    for(int i = 0; i < 5; i++){
        printf("%d\n",*(p+i));
    }


    *p = *p * 2;
    *(p+1) = *(p+1) * 2;
    *(p+2) = *(p+2) * 2;
    *(p+3) = *(p+3) * 2;
    *(p+4) = *(p+4) * 2;

    printf("modified array using the pointer \n");
    for(int i = 0; i < 5; i++){
        printf("%d\n",*(p+i));
    }

    printf("modified array using the array name \n");
    for(int i = 0; i < 5; i++){
        printf("%d\n",*(a+i));
    }

    return 0;

}