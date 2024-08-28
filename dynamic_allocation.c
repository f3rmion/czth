#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct employee_t {
    int id;
    int income;
    bool staff;
};

void initialize_employee(struct employee_t *e) {
    e->id = 0;
    e->income = 0;
    e->staff = false;

    return;
}

int main() {
    // dynamic values that came from somewhere else
    int n = 4;

    struct employee_t *employees = malloc(sizeof(struct employee_t) *  n);
    // check if memory allocation was successful
    if (employees == NULL) {
        printf("The allocator failed");
        return -1;
    }

    initialize_employee(&employees[0]);

    printf("%d\n", employees[0].income);

    // Give memory back to avoid memory leak!
    free(employees);
    
    // we want to delete the pointer to not point to memory
    // that has already been deallocated
    employees = NULL;

    return 0;
}