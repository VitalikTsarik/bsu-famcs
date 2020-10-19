#!/usr/bin/env bash

mkdir release
cd release
cmake -DCMAKE_BUILD_TYPE=Release -G "CodeBlocks - Unix Makefiles" ..
make

printf '' >"../reports/output.txt"

echo 2 7 >>"../reports/output.txt"
for n in 500 2100; do
  echo $n >>"../reports/output.txt"
  for r in 1 2 5 10 25 50 100; do
    ./lab1 -n $n -r $r -o "../reports/output.txt"
  done
done

output_file="../reports/extra_analise_output.txt"
n=2100
echo 1 5 >>output_file
printf '' >$output_file
echo $n >>$output_file
for r in 15 20 25 30 35 ; do
  ./lab1 -n $n -r $r -o $output_file
done

echo "done"
