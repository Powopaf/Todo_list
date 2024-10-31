#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>


char* build_string(char* task, char* day, char* month, char* year) {
   /*
    * the \n in include in ther char* year
    */

    size_t length = strlen(task) + strlen(day) + strlen(month) + strlen(year) + 7;
    char* str;
    struct date dt;
    getdate(&dt);
    if (atoi(year) < dt.da_year) {
        str = malloc(sizeof(char) * (length + 19);
        sprintf(str, "\033[0;31mTask is passed : %s %s %s %s\033[0m", task, day, month, year);
    return str;
}
