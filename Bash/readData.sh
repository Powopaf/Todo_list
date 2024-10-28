#!/bin/bash

# color for fancy message
reset='\033[0m'
red='\033[31m'
green='\033[32m'
orange='\033[33m'

color_msg() {
    read -ra todo_date <<<"$1"
    day=$(($(date +'%d')))
    month=$(($(date +'%m')))
    year=$(($(date +'%Y')))
    y=$((${todo_date[3]}))
    m=$((${todo_date[2]}))
    d=$((${todo_date[1]}))
    if (( year > y )); then
        echo -e "${red}Task is passed : " 
     
    elif (( month > m )); then
        echo -e "${red}Task is passed : "
    
    elif (( day > d && month > m)); then
        echo -e "${red}Task is passed : "
    
    elif (( year < y )); then
        echo -e "${green}"
    
    elif (( day == d )); then
        echo -e "${red}Finish Today !! : "
    
    elif (( ((day + 10) % 30) >= d )); then
        echo -e "${orange}"
    
    else
        echo -e "${green}"
    fi
}

while IFS= read -r line; do
    # Split the line into an array based on spaces
    read -r -a array <<< "$line"
  
    # build message to print
    if [ -n "$line"  ]; then
        msg=""
        res=""
        for item in "${array[@]}"; do
            msg+="$item "
        done
        #echo "$msg"
        res+=$(color_msg "$msg")
        res+="$msg"
        res+="${reset}"
        echo -e "$res"
    fi
done < "data"

