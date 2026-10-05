#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int n;
    int sum;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("Array after calloc: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }


    printf("\nEnter %d numbers: ", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        sum = sum + *(arr + i);
    }

    printf("Updated array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nAverage of the array: %.2f\n",(double)sum/n);

    free(arr);

    return 0;
}
