#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr;
    int *new_arr;
    int n = 10;
    int n_new = 5;



    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("Enter %d numbers: ", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        
    }

    new_arr = (int *)realloc(arr, n_new * sizeof(int));


    if (new_arr == NULL) {
        printf("Failed to reallocate memory\n");
        free(arr);
        return 1;
    }

    printf("Array after resizing: ");

    for (int i = 0; i < n_new; i++) {
        printf("%d ", new_arr[i]);
    }


    free(new_arr);

    return 0;
}
