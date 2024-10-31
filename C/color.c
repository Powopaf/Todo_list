#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* build_string(char* task, char* day, char* month, char* year) {
   /*
    * the \n in include in ther char* year
    * str must be free
   */

    size_t length = strlen(task) + strlen(day) + strlen(month) + strlen(year) + 8;
    char* str;// = calloc(length, sizeof(char));
    time_t current_time = time(NULL);
    struct tm *tm_local = localtime(&current_time);
    int y = tm_local->tm_year + 1900;
    if (atoi(year) < y) {
        str = malloc(sizeof(char) * (length + 22));
        sprintf(str, "\033[0;31mTask is passed : %s %s %s %s\033[0m\n", task, day, month, year);
        return str;
    }
    else { 
        str = "";
        return str;
    }
}
