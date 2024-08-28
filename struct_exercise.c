#include <stdio.h>

struct Employee {
    int age;
    char name[30];
};

int main(int argc, char **argv) {

    struct Employee emp = {42, "Steve"};

    printf("%s, aged %d years\n", emp.name, emp.age);

    return 0;

}