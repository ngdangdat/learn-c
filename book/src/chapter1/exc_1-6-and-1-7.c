#include <stdio.h>

int main() {
    printf("first char: ");
    int c = getchar();
    int result = (c == EOF);
    printf("(c == EOF) = [%d]\n", result);
    printf("value of EOF = [{%c}]", EOF);
    return 0;
}
