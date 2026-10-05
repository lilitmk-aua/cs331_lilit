#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

int main() {
    int *arr;
    int n;
    int highest = 0;
    int lowest = 100;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    printf("Enter the grades: ");
    
    for (int i = 0; i < n; i++) {
        scanf("%d", arr+i);
        if(arr[i] > highest) highest = arr[i];
        if(arr[i] < lowest) lowest = arr[i];
        
    }

    printf("Highest grade: %d \n",highest);
    printf("Lowest grade: %d \n",lowest);

    free(arr);

    return 0;
}
