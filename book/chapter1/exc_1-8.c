#include <stdio.h>

int main() {
    int c, blankCount = 0, tabCount = 0, newLineCount = 0;
    while ((c = getchar()) != EOF) {
        switch(c) {
            case '\t':
                ++tabCount;
                break;
            case ' ':
                ++blankCount;
                break;
            case '\n':
                ++newLineCount;
                break;
            default:
                break;
        }
    }
    printf("bc\ttc\tnlc\n");
    printf("%d\t%d\t%d\n", blankCount, tabCount, newLineCount);

    return 0;
}