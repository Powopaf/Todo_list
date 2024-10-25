#!/bin/bash

# display the definition of all flags

add="to add a task use\n -add [task] [day] [month]\n"
help_list=("$add")

remove="to remove a taske use\n -del [task name]\n"
help_list+=("$remove")

if [ $# -eq 0 ]; then
    for h in "${help_list[@]}"; do
        echo -e "$h"
    done
elif [ "$1" = "add" ]; then
    echo -e "$add"
elif [ "$1" = "del" ]; then
    echo -e "$remove"
else
    for h in "${help_list[@]}"; do
        echo -e "$h"
    done
fi
