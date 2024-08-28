#include <stdio.h>

union myunion {
    int i;
    char c;
    short s;
};

int main() {
    union myunion u;
    u.i = 0x41424344;
    printf("%hx %hhx\n", u.s, u.c);
}