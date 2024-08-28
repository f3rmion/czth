#include <stdio.h>

// syntax of a function
// return_type name(list of arguments) {logic}

int add(int x, int y) {
    int z = x + y;

    return z;
}

int main() {
    int other_int = add(1, 2);
    printf("%d\n", other_int);

    return 0;
}