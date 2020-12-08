#!/bin/bash

mpicc src/main.c -o .out/gauss.out -lm || exit 1
mpirun -np "$1" .out/gauss.out "$2" 150
