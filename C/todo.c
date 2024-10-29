#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(char* task, char* day, char* month, char* year) {
    // write in the data file the new task to add
    // FORMAT :
    //\ntask day month year
    FILE* file = fopen("data", "a+");
    size_t length = strlen(task) + strlen(day) + strlen(month) + strlen(year) + 5;
    char* task_to_add = malloc(sizeof(char) * length);
    task_to_add[0] = '\n';
    strcat(task_to_add, task);
    task_to_add[strlen(task) + 1] = ' ';
    strcat(task_to_add, day);
    task_to_add[strlen(task) + strlen(day) + 2] = ' ';
    strcat(task_to_add, month);
    task_to_add[strlen(task) + strlen(day) + strlen(month) + 3] = ' ';
    strcat(task_to_add, year);
    fprintf(file, task_to_add);
}

int main(int argc, char* argv[]) {
    if (strcmp(argv[1], "add") && argc == 6) {
        // TODO : make sure argv[2,3,4,5] are valid
        add(argv[2], argv[3], argv[4], argv[5]);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
