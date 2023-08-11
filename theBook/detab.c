// Exercise 1-20

/* Write a program  de-tab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?*/

#include <stdio.h>

#define TAB 8   /* size of a tab */

int main()
{
char c;
int i,column = 0;

while ((c = getchar()) != EOF) {
    if(c == '\n')
        column = -1;

    if(column >= TAB)
        column = 0;

    if (c == '\t') {
        for (i = column; i < TAB; i++){
            putchar(' ');
        }
        column = -1;
    }
    else{
        putchar(c);
        }
    column++;
}
return 0;
}