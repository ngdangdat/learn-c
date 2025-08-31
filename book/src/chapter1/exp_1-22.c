#include <stdio.h>
#define WRAP_SIZE 10
#define TAB_LENGTH 8 /* standard tab length */
#define CURTAB(c)  (TAB_LENGTH - (c % TAB_LENGTH))
#define NO_BLANK -1
#define BOOL_TRUE 1
#define BOOL_FALSE 0


int lastBlankPosition(char line[], int len) {
    int lbp = NO_BLANK;
    for (int i = 0; i < len; ++i) {
        if (line[i] == '\t' || line[i] == ' ' || line[i] == '\n') {
            lbp = i;
        }
    }
    return lbp;
}


int main() {
    int c, pos, col, lbc, i, j;
    pos = col = 0;
    char line[WRAP_SIZE];
    while((c = getchar()) != EOF) {
        line[pos++] = c;
        col += (c == '\t') ? CURTAB(c) : 1;

        if (col >= WRAP_SIZE || col == '\n') {
            line[pos] = '\0';

            if ((lbc = lastBlankPosition(line, pos)) == NO_BLANK) {
                printf("1. lbc=[%d]", lbc);
                for (int i = 0; i < pos; i++) {
                    putchar(line[i]);
                }
                pos = col = 0;
            } else {
                printf("2. lbc=[%d]", lbc);
                for (i = 0; i < lbc; i++) {
                    putchar(line[i]);
                }
                // put the rest out
                for (i = 0, j = lbc + 1, col = 0; j < pos; ++j) {
                    line[i] = line[j];
                    col += (line[i] == '\t') ? CURTAB(col) : 1;
                }
                pos = i;
            }
            putchar('\n');
        }
    }
    return 0;
}
