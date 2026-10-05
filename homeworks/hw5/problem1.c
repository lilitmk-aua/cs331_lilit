#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

int main() {
    int *arr;
    int n;
    int sum;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("Enter %d numbers: ", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        sum = sum + *(arr + i);
    }

    printf("Sum of the array: %d \n",sum);

    free(arr);

    return 0;
}