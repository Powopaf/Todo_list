#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* task_filename = "data"; // if task_filename is change put the new
                                    // name in the .gitignore file
                                    // file is create if it do not exist

int add(char* task, char* day, char* month, char* year) {
    // write in the data file the new task to add
    // FORMAT :
    //\ntask day month year

    FILE* file = fopen(task_filename, "a+");
    if (file == NULL) { 
        printf("\033[0;31mFailed to open file data in add()(fopen() error)\033[0m\n"); 
        return EXIT_FAILURE; 
    }
    
    size_t length = strlen(task) +strlen(day) + strlen(month) + strlen(year) + 5;
    char* task_to_add = malloc(sizeof(char) * length);
    if (task_to_add == NULL) { 
        printf("\033[0;31mFailed To add task %s (malloc failure)\033[0m\n", task); 
        return EXIT_FAILURE; 
    }

    if (sprintf(task_to_add, "%s %s %s %s\n", task, day, month, year) < 0) { 
        printf("\033[0;31mFail to build string with sprintf()\033[0m\n"); 
        return EXIT_FAILURE; 
    }
    
    if (fprintf(file, task_to_add) < 0) { 
        printf("\033[0;31mFail To write in file (fprintf() error\033[0m\n"); 
        return EXIT_FAILURE; 
    }
    
    free(task_to_add);
    printf("Task: %s was successfuly added.\n", task);
    return EXIT_SUCCESS;
}

int help(char display) {
    /*
     * diplay   = a -> print ONLY add help
     *          = \0 -> print all help possible
    */
    static char* help_add = "To add a new task the argument must be :\n\033[0;35madd\033[0m \033[0;34mtask day month year\033[0m";
    if (display == 'a') {
        printf("%s\n", help_add);
        return EXIT_SUCCESS;
    }
    else {
        char* list_help[1] = { help_add };
        for (size_t i = 0; i < 1; i++) {
            printf("%s\n", list_help[i]);
        }
    return EXIT_SUCCESS;
    }
}

int read_data() {
    // print all line in the [task_filename]
    FILE* file = fopen(task_filename, "r");
    if (file == NULL) {
        printf("\033[0;31mFailed to open file data in read_data() (fopen() error)\033[0m\n");
        return EXIT_FAILURE;
    }
    const char* separator = " ";
    char line[128]; 
    while (fgets(line, 128, file) != NULL) {
        char* token = strtok(line, separator);
        while (token != NULL) {
            // TODO: call function for fancy color
            printf("%s ", token);
            token = strtok(NULL, separator);
        }
    }
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        return read_data();
    }

    else if (strcmp(argv[1], "add") == 0 && argc == 6) {
        // TODO : make sure argv[2,3,4,5] are valid
        return add(argv[2], argv[3], argv[4], argv[5]);
    }

    else {
        return help('\0');
    }
}
