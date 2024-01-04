#include <stdio.h>
#define MAX_BLANK_EACH 1

int main() {
    int ip;
    int blankCount = 0;
    while ((ip = getchar()) != EOF) {
        if ((ip == ' ') && (blankCount == MAX_BLANK_EACH)) continue;
        if ((ip == ' ')) {
            blankCount += 1;
        } else {
            blankCount = 0;
        }
        printf("%c", ip);
    }
    return 0;
}