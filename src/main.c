#include "function.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char ch;
    do {
        genering_word();
        output_inf_word();
        correct();
        printf("\n End? y/n \n");
        scanf("%s", &ch);
    } while (ch != 'y');
    return 0;
}
