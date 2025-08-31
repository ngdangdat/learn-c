#include <stdio.h>
#include <stdlib.h>

/**
Correct this code to update the value in the heap 
to 10 before giving the address to main
**/

int foo(int **ptr) {
    int value = 10;
    *ptr = (int *)malloc(sizeof(int));  

    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        perror("malloc");
        return -1;
    }

    **ptr = value; 
    return 0;
}
