#!/bin/bash

# color for fancy message
reset='\033[0m'
red='\033[31m'
green='\033[32m'
orange='\033[33m'

color_msg() {
    read -ra todo_date <<<"$1"
    day= $(( $(date +'%d') ))
    month= $(( $(date +'%m') ))
    year= $(( $(date +'%Y') ))
    y= $((${todo_date[3]}))
    m= $((${toto_date[2]}))
    d= $((${todo_date[1]}))
    if (( year -gt y ))
        echo "${green}" 
    elif (( $year > $y )) || (( $month > $m )) || (( $day > $d )); then
        echo "${red} Task is passed : "
    elif (( year < y )) || (( month < $m )); then
        echo "${green}"
    elif (( day == d )); then
        echo "${red} Finish Today !! : "
    elif (( $day + 15 >= $d )); then
        echo "${orange}"
    else
        echo "${green}"
    fi
}



while IFS= read -r line; do
  # Split the line into an array based on spaces
  read -r -a array <<< "$line"
  
  # build message to print
  if [ -n "$line"  ]; then
    msg=""
    for item in "${array[@]}"; do
        msg+="$item "
    done
    res=$(color_msg $msg)
    res+="${reset}"
  fi
done < "data"

