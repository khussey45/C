// Exercise 1-20

/* Write a program  de-tab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?*/


#include <stdio.h>
#include <stdlib.h>

#define TABWIDTH 8

int main(void)
{
    int i;
    int c, col, spaces;

    col = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = TABWIDTH - col % TABWIDTH;
            for (i = 0; i < spaces; ++i)
                putchar(' ');
            col = col + spaces;
        } else {
            putchar(c);
            col = col + 1;
            if (c == '\n')
                col = 0;
        }
    }
    return EXIT_SUCCESS;
}