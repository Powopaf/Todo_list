#include <err.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "verif.h"
#include "color.h"

const char* task_filename = "data"; // if task_filename is change put the new
                                    // name in the .gitignore file
                                    // file is create if it do not exist

static int add(char* task, char* day, char* month, char* year) {
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
    fclose(file);
    printf("Task: %s was successfuly added.\n", task);
    return EXIT_SUCCESS;
}

static int help(char display) {
    /*
     * diplay   = a -> print ONLY add help
     *          = \0 -> print all help possible
    */
    static char* g1 = "Bellow are the command you you can use for add and delete task\n";
    char* g3 = "\033[35mhelp \033[0m\033[34del\033[0m to display add help only\n\033[35help\033[0m \033[34mdel\033[0m to diplay delete help onlyi\n";
    char* g2 = "Note that if no task where ever added ther will be error when printing task or deleting them\n";
    static char* help_add = "To add a new task the argument must be :\n\033[0;35madd\033[0m \033[0;34mtask day month year\033[0m\n";
    static char* help_del = "To delete a new task the do :\n\033[35mdel \033[0m\033[34mtask_name\033[0m\n";
    if (display == 'a') {
        printf("%s", help_add);
        return EXIT_SUCCESS;
    }
    else if (display == 'd') {
        printf("%s", help_del);
        return EXIT_SUCCESS;
    }
    else {
        char* list_help[5] = { g1, g2, g3, help_add, help_del };
        for (size_t i = 0; i < 5; i++) {
            printf("%s", list_help[i]);
        }
    return EXIT_SUCCESS;
    }
}

static int read_data() {
    // print all line in the [task_filename]
    FILE* file = fopen(task_filename, "r");
    if (file == NULL) {
        printf("\033[0;31mFailed to open file data in read_data() (fopen() error)\033[0m\n");
        return EXIT_FAILURE;
    }
    const char* separator = " ";
    char line[128];
    char* to_print;
    char* words[4];
    size_t i = 0;
    while (fgets(line, 128, file) != NULL) {
        char* token = strtok(line, separator);
        i = 0;
        while (token != NULL) {
            words[i] = token;
            token = strtok(NULL, separator);
            i++;
        }
        to_print = build_string(words[0], words[1], words[2], words[3]);
        printf("%s", to_print);
        free(to_print);
    }
    fclose(file);
    return EXIT_SUCCESS;
}

static int delete_task(char* task) {
    FILE *file = fopen(task_filename, "r"); // file must exist
    if (file == NULL) { return EXIT_FAILURE; }
    FILE *tempfile = fopen("t_data", "w");
    char line[128];
    while (fgets(line, 128, file)) {
        char f_task[118];
        sscanf(line, "%s", f_task);
        if (strcmp(task, f_task) != 0) {
            fputs(line, tempfile);
        }
    }
    fclose(file);
    fclose(tempfile);
    remove(task_filename);
    rename("t_data", task_filename);
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        return read_data();
    }

    else if (strcmp(argv[1], "add") == 0 && argc == 6 && check_date(argv[3], argv[4], argv[5]) == 'T') {
        return add(argv[2], argv[3], argv[4], argv[5]);
    }
    else if (strcmp(argv[1], "del") == 0 && argc >= 2) {
            return delete_task(argv[2]);
    }
    else if (strcmp(argv[1], "help") == 0 && argc == 2){
        if (strcmp(argv[2], "add") == 0) { return help('a'); }
        else if (strcmp(argv[2], "del") == 0) { return help('d'); }
        else { return help('\0'); }
    }
    else { return help('\0'); }
}
