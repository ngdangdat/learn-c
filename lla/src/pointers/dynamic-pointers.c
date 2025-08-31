#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_EMPLOYEE 1000

struct employee_t {
  int id;
  int income;
  bool staff;
};

int initialize_employee(struct employee_t *e) {
  static int currentId = 0;
  currentId++;

  e->id = currentId;
  e->income = 0;
  e->staff = false;

  return currentId;
}

int main() {
  int n = 4;
  struct employee_t *employees = malloc(sizeof(struct employee_t)*n);
  if (employees == NULL) {
    printf("the allocator failed\n");
    return -1;
  }
  for (int i = 0; i < n; i++) {
    int employeeId = initialize_employee(&employees[i]);
    printf("New employee ID: %d\n", employeeId);
  }
  free(employees);
  employees = NULL;

  return 0;
}
