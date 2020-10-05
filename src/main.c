#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

int main()
{
    char ch;
    do {
        genering_word();
        output_inf_word();
        printf("\n End? y/n \n");
        scanf("%s", &ch);
    } while (ch != 'y');
    return 0;
}
