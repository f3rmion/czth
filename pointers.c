#include <stdio.h>


int main() {
    // create integer we'd like to reference
    int x = 3;

    // create pointer that points to x
    // * character notes the type is a pointer
    // & character gets the "address of" x and puts that in pX
    int *pX = &x;

    // to use a pointer, we need to "dereference" it
    // simply by adding the * to the name of the pointer
    printf("%d\n", *pX);

    // get the address of x
    printf("%p\n", pX);
}