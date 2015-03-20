#!/bin/bash

read -p "NO: " no
input="$no".in
output="$no".out
./Random > $input
./gcd_by_binary < $input > $output
echo $input
cat $input
echo ""
echo $output
cat $output
echo ""
