#include <stdio.h>
#define PRINT_THRESHOLD 80
#define MAXLINE 1000


// customised getline
int cgetline(char line[], int maxline);


int main() {
    char line[MAXLINE];
    int len;
    while ((len = cgetline(line, MAXLINE)) > 0) {
        printf("len=[%d]\n", len);
        if (len > PRINT_THRESHOLD) {
            printf("len=%d, line=%s", len, line);
        }
    }
    return 0;
}


int cgetline(char line[], int maxline) {
    int i, c;
    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != '\n' && c != EOF; i++) {
        printf("cgetline i=%d\n", i);
        line[i] = c;
    }
    printf("cgetline out scope i=%d\n", i);
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    printf("cgetline before return i=%d\n", i);
    return i;
}
