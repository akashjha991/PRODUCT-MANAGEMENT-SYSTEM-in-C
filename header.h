// in linux system do not define #include <window.h>

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[94m"
#define ANSI_BGCOLOR_RED   "\x1b[41m"


#ifdef WIN32
#include<windows.h>
#endif
#ifndef PRODUCT
#define PRODUCT
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <setjmp.h>

typedef struct product
{
    int id;
    char name[50],username[10], password[10];
    float price;
    int quantity;

} product;
#endif

/* if you include this header file again and again on other files then it will conflict in that files that's why we useed this #ifndef
macro in which it will define the macro if it is not included previously*/

// Note: if you will not add 8th line then this error : we redefinition struct product will occur.

