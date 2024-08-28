#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_CHARS 64
#define MAX_EMPLOYEES 1000

struct employee_t {
    int id;
    char firstname[MAX_NAME_CHARS];
    char lastname[MAX_NAME_CHARS];
    float income;
    bool is_manager;
};

int main() {
    struct employee_t employees[MAX_EMPLOYEES];

    int i = 0;
    for (i = 0; i < MAX_EMPLOYEES; i++) {
        memcpy(employees[i].firstname, "John", 5);
        memcpy(employees[i].lastname, "Doe", 4);
        employees[i].id = i;
        employees[i].income = 0;
        employees[i].is_manager = false;
    }

    printf("%d\n", employees[10].id);
    printf("%s %s\n", employees[10].firstname, employees[10].lastname);
    printf("%f\n", employees[10].income);
}