/**
 * Count lines, characters, words from the input
*/
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c, nl = 0, nc = 0, nw = 0;
    int STATE = OUT;
    while((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\t' || c == '\n' || c == ',' || c == '-') {
            STATE = OUT;
        } else if (STATE == OUT) {
            STATE = IN;
            ++nw;
        }
    }
    printf("line count: %d, char count: %d, word count: %d\n", nl, nc, nw);
    return 0;
}
