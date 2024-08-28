#include <stdio.h>

// if we want to serialize this data and work on
// it between two different systems that might have
// different architectures, there's a chance that the
// structures may change between these systems
// Here the structure should only be 5 bytes
// But there is a chance that the structure is actually
// 8 bytes or even 16 bytes due to alignment issues
// We fix this by adding the `packed` attribute
// This will create the same structure but ensures
// that the compiler doesn't add any special sauce
// in between the elements so we can ensure it's 
// the same size on multiple systems.
struct __attribute__((__packed__))  mystruct {
    int i;
    char c;
};

int main() {
    struct mystruct s;
    printf("Size of mystruct: %d\n", sizeof(struct mystruct));
}