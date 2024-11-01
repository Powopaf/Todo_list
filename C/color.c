#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* build_string(char* task, char* day, char* month, char* year) {
   /*
    * the \n in include in ther char* year
    * str must be free
   */

    size_t length = strlen(task) + strlen(day) + strlen(month) + strlen(year) + 13;
    char* str;
    time_t current_time = time(NULL);
    struct tm *tm_local = localtime(&current_time);
    int y = tm_local->tm_year + 1900;
    if (atoi(year) < y) {
        str = malloc(sizeof(char) * (length + 17));
        sprintf(str, "\033[31mTask is passed : %s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
    else if (atoi(year) > y) {
        str = malloc(sizeof(char) * length);
        sprintf(str, "\033[32m%s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
    else if (tm_local->tm_mon > atoi(month)) {
        str = malloc(sizeof(char) * (length + 17));
        sprintf(str, "\033[31mTask is passed : %s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
    else if (tm_local->tm_mday > atoi(day) && tm_local->tm_mon == atoi(month)) {
        str = malloc(sizeof(char) * (length + 17));
        sprintf(str, "\033[31mTask is passed : %s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
    else if ((tm_local->tm_mon + 1) == atoi(month) && ((tm_local->tm_mday + 10) % 30) >= atoi(day)) {
        str = malloc(sizeof(char) * length);
        sprintf(str, "\033[33m%s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
    else if (tm_local->tm_mon == atoi(month) && (tm_local->tm_mday + 10) >= atoi(day)) {
        str = malloc(sizeof(char) * length);
        sprintf(str, "\033[33m%s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
    else {
        str = malloc(sizeof(char) * length);
        sprintf(str, "\033[32m%s %s %s %s\033[0m", task, day, month, year);
        return str;
    }
}
