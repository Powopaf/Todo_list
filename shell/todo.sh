#!/bin/bash

if [ $# -eq 0 ]; then
    if [ -s "data" ]; then
        echo "to do :"
        exit 0
    else
        blue='\033[34m'
        reset='\033[0m'
        echo -e "Nothing to do :
        use ${blue}-add${reset} to add something to do
        use ${blue}-help${reset} to see documentation"
        exit 0
    fi

elif [ "$1" = "-add" ]; then
    if [ $# -ne 4 ]; then
        red='\033[31m'
        reset='\033[0m'
        blue='\033[34m'
        echo -e "${red}Invalide argument to add a new task${reset}

try ${blue}-help${reset} to add properly a new task"
    exit 0
    else
        echo "" >> data
        echo "$2 $3 $4 0" >> data
        echo "Task $2 succesfuly add"
        exit 0
    fi
fi
