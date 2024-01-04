#include <stdio.h>
#define MAX_BLANK_EACH 1

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        switch(c) {
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            default:
                putchar(c);
                break;
        }
    }
    return 0;
}