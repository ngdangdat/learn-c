#include <stdio.h>
#define MAX_LENGTH 100
#define BAR_CHAR '-'

void main() {
    int max_length = 0, max_freq = 0;
    int c;
    int count_arr[MAX_LENGTH];
    int curr_length = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        count_arr[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (curr_length > 0) {
                ++count_arr[curr_length];
                if (count_arr[curr_length] > max_freq) {
                    max_freq = count_arr[curr_length];
                }
                curr_length = 0;
                continue;
            }
        }
        ++curr_length;
        if (curr_length > max_length) {
            max_length = curr_length;
        }
    }
    printf("Freq\t");
    for (int i = 0; i <= max_length; ++i) {
        int freq = count_arr[i];
        if (freq == 0) continue;
        printf("%d\t", freq);
    }
    printf("\n");

    for (int i = max_freq; i > 0; --i) {
        printf("|\t");
        for (int j = 0; j <= max_length; j++) {
            int freq = count_arr[j];
            if (freq == 0) continue;
            // printf("check freq %d, i %d, max_freq %d\n", freq, i, max_freq);
            char dc;
            int comp = max_freq - freq;
            if (i <= freq) {
                dc = BAR_CHAR;
            } else {
                dc = ' ';
            }
            printf("%c\t", dc);
        }
        printf("\n");
    }
    printf("Length\t");
    for (int i = 0; i <= max_length; i++) {
        int freq = count_arr[i];
        if (freq == 0) continue;

        printf("%d\t", i);
    }
    printf("\n");
}
