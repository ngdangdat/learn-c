// arrays
#include <stdio.h>
#define MAXLINE 5 // max input line size

int cgetline(char line[], int maxline);
void copy(char to[], char from[]);


int main() {
    int len;
    char line[MAXLINE];

    while ((len = cgetline(line, MAXLINE)) > 0) {
        printf("max_len=%d, current_len=%d, line=%s", MAXLINE, len, line);
    }
    return 0;
}

int cgetline(char line[], int maxline) {
    int i, c, l = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < maxline - 1) {
            l++;
            line[i] = c;
        }
    }
    if (c == '\n') {
        line[l] = c;
        ++l;
        ++i;
    }
    line[l] = '\0';
    return i;
}


void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') ++i;
}
