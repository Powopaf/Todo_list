#!/bin/bash

# display the definition of all flags

add="todo -add [task] [day] [month] \n You can add a new task like this"
help_list=("$add")

if [ $# -eq 0 ]; then
    for h in "${help_list[@]}"; do
        echo -e "$h"
    done
elif [ "$1" = "add" ]; then
    echo -e "$add"
else
    for h in "${help_list[@]}"; do
        echo -e "$h"
    done
fi
