// (C) Maryam Esmaeili Darestani, Lucas Nordgren, Hannah Shiels: Group 6 2022
// Work package 2
// Exercise 4
// Submission code:



/**
* Include section
*/

#include <stdio.h>


/**
* Main body
*/

int main (void)
{
    char b[] = "maryam!";
    char *example = &b;
    int a = 125;
    int *p = &a;
    printf("%p\n", *example);
    printf("%p\n%p\n", *p, &a);
    //printf("%s\n", b);
    return 0;
}