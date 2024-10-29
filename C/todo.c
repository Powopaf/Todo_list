#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add(char* task, char* day, char* month, char* year) {
    // write in the data file the new task to add
    // FORMAT :
    //\ntask day month year
    FILE* file = fopen("data", "a+");
    size_t length = strlen(task) +strlen(day) + strlen(month) + strlen(year) + 5;
    char* task_to_add = malloc(sizeof(char) * length);
    sprintf(task_to_add, "%s %s %s %s\n", task, day, month, year);
    fprintf(file, task_to_add);
    free(task_to_add);
    printf("Task: %s was successfuly added.\n", task);
}

int main(int argc, char* argv[]) {
    if (strcmp(argv[1], "add") == 0 && argc == 6) {
        // TODO : make sure argv[2,3,4,5] are valid
        add(argv[2], argv[3], argv[4], argv[5]);
        return EXIT_SUCCESS;
    }
    printf("error\n");
    return EXIT_FAILURE;
}
