#include <stdio.h>
#define TABSIZE 2


int main() {
    int c, spaceCount = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') spaceCount = 0;
        if (c == ' ') {
            ++spaceCount;
        } else {
            if (spaceCount > 0) {
                for (int i = spaceCount; i > 0; --i) {
                    putchar(' ');
                }
            }
            putchar(c);
        }
        if (spaceCount == TABSIZE) {
            putchar('\\');
            putchar('t');
            spaceCount = 0;
            continue;
        }
    }

    return 0;
}
