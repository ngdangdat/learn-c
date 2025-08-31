/**
 * Exercise 1-13. Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 
*/
#include <stdio.h>
#define MAX_LENGTH 100
#define BAR_CHAR '|'

/**
1 -------------
2 ------------
3 ------------------
4 ----------------------
5 --------------
*/

void main() {
    /**
     * 1. count number of escape characters -> array length
     * 2. catch escape character, count length
    */
    int max, c;
    max = 0;
    int count_arr[MAX_LENGTH];
    int curr_length = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        count_arr[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (curr_length > 0) {
                count_arr[curr_length]++;
                curr_length = 0;
                continue;
            }
        }
        ++curr_length;
        if (curr_length > max) {
            max = curr_length;
        }
    }

    printf("max length: %d\n", max);
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (count_arr[i] == 0) continue;
        int freq = count_arr[i];
        printf("%d\t", i);
        for (int j = 0; j < freq; j++) {
            printf("%c", BAR_CHAR);
        }
        printf(" %d\n", freq);
    }
}
