#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

int genering_word()
{
    int word = 0;
    char ch;
    int k = 1;
    srand(time(NULL));
    FILE *tf, *pr;
    tf = fopen("Infinitive.txt", "r");
    if (tf == NULL) {
        perror("Error opening infinitive file");
        return -1;
    }
    pr = fopen("verbs.txt", "w");
    if (pr == NULL) {
        perror("Error opening verbs file");
        return -1;
    }
    int num_word = rand() % 122;
    while ((ch = fgetc(tf)) != EOF) {
        if (ch == ' ') {
            word++;
        }
        if (k == num_word) {
            if (word == 0) {
                fputc(ch, pr);
            }
            if (word == 1) {
                fputc(ch, pr);
            }
            if (word == 2) {
                fputc(ch, pr);
            }
        }
        if (ch == '\n') {
            k++;
            word = 0;
        }
    }
    fclose(tf);
    fclose(pr);
    return 0;
}

int output_inf_word()
{
    char ch;
    int word = 0;
    FILE* pr;
    pr = fopen("verbs.txt", "r");
    if (pr == NULL) {
        perror("Error opening verbs file");
        return -1;
    }
    printf("Infinitive: ");
    while ((ch = fgetc(pr)) != EOF) {
        if (ch == ' ')
            word++;
        if (word == 0)
            printf("%c", ch);
    }
    printf("\n");
    fclose(pr);
    return 0;
}

int input_simple_word(char *simp, char *filename)
{
    char ch, sl1[100];
    int word = 0, i = 0, c = 0, t = 0;
    FILE* pr;
    pr = fopen(filename, "r");
    if (pr == NULL) {
        perror("Error opening file");
        return -1;
    }
    while ((ch = getc(pr)) != EOF) {
        if (ch == ' ')
            word++;
        if (word == 1 && ch != ' ') {
            sl1[i] = ch;
            i++;
        }
    }
    
    for (t = 0; t < i; t++) {
        if (sl1[t] == simp[t])
            c++;
    }
    fclose(pr);
    if (c == i) {
        return 1;
    } else {
        return 0;
    }
}
