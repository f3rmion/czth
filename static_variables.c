#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct employee_t {
    int id;
    int income;
    bool staff;
};

int initialize_employee(struct employee_t *e) {
    // static variable will be initialised in global scope
    // this lives in the data section of the ELF and hence
    // it does not get destroyed when the function returns
    // we track how often this function has been called using
    // the numEmployees int
    // global-ish variable behaviour, BUT
    // scope of this variable is local to this function!
    static int numEmployees = 0;
    numEmployees++;

    // id is now auto-incremental
    e->id = numEmployees;
    e->income = 0;
    e->staff = false;

    return numEmployees;
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

    for (int i = 0; i < n; i++) {
        initialize_employee(&employees[i]);
        printf("New employee, ID is %d\n", employees[i].id);
    }

    // Give memory back to avoid memory leak!
    free(employees);
    
    // we want to delete the pointer to not point to memory
    // that has already been deallocated
    employees = NULL;

    return 0;
}