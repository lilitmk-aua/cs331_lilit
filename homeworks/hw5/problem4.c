#include <stdio.h>
#include <stdlib.h>

int main() {
    char **arr;
    char **new_arr;
    int n = 3;
    int n_new = 5;



    arr = (char**)malloc(n * sizeof(char*));

    if (arr == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (char*)malloc(50 * sizeof(char));
        if (arr[i] == NULL) {
            printf("Failed to allocate memory\n");
            return 1;
        }
        
    }

    printf("Enter %d strings: ", n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", *(arr+i));
        
    }

    new_arr = (char**)realloc(arr, n_new * sizeof(char*));

    if (new_arr == NULL) {
        printf("Failed to allocate memory\n");
        free(arr);
        return 1;
    }

    for (int i = n; i < n_new; i++) {
        new_arr[i] = (char*)malloc(50 * sizeof(char));
        if (new_arr[i] == NULL) {
            printf("Failed to allocate memory\n");
            return 1;
        }
        
    }

    printf("Enter %d more strings: ", n_new - n);
    
    for (int i = n; i < n_new; i++) {
        scanf("%s", *(new_arr+i));
        
    }

    printf("All strings: ");

    for (int i = 0; i < n_new; i++) {
        printf("%s ", new_arr[i]);
    }


    for (int i = 0; i < n_new; i++) {
        free(new_arr[i]);
    }
    free(new_arr); 

    return 0;
}
