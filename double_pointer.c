#include <stdio.h>
#include <stdlib.h>

typedef enum {
    STATUS_GOOD,
    STATUS_BAD
} status_t;

// we want to create a funtion foo
// that resizes an array using `realloc`
// the function should accept a double pointer
// to the array so that it can modify the original pointer
status_t foo(int **arr, size_t new_size) {
    int *temp = realloc(*arr, new_size * sizeof(int));
    if (temp == NULL) {
        // handle realloc failure
        printf("Memory allocation failed\n");
        return STATUS_BAD;
    }
    *arr = temp;
    return STATUS_GOOD;
}

int main() {
    size_t initial_size = 5;
    size_t new_size = 10;

    int *arr = malloc(initial_size * sizeof(int));
    if (arr == NULL) {
        // handle malloc failure
        printf("Memory allocation failed");
        return 1;
    }

    // initialize the array
    for (size_t i = 0; i < initial_size; i++) {
        arr[i] = i;
    }

    // print the initial array
    printf("Initial array:\n");
    for (size_t i = 0; i < initial_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // call foo to resize the array
    if (STATUS_BAD == foo(&arr, new_size)) {
        printf("Ohoh");
        return -1;
    }

    // initialize the new part of the array
    for (size_t i = initial_size; i < new_size; i++) {
        arr[i] = i;
    }

    // print the resized array
    printf("Resized array:\n");
    for (size_t i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free the memory
    free(arr);
    return 0;
}