#!/bin/bash

> reports/output.txt
echo 4 >>"reports/output.txt"
MATRIX_SIZE=1000
printf "Matrix size is %s\n" $MATRIX_SIZE
for i in {1,2,3,4}; do
  printf "\n-------- Processes: %s ---------\n" "$i"
  bash run.sh $i $MATRIX_SIZE || exit 1
done
