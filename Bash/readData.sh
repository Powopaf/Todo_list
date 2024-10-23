#!/bin/bash

while IFS= read -r line; do
  # Split the line into an array based on spaces
  read -r -a array <<< "$line"
  
  # build message to print
  if [ -n "$line"  ]; then
    msg=""
    for item in "${array[@]}"; do
        msg+="$item "
    done
    echo "$msg"
  fi
done < "data"

