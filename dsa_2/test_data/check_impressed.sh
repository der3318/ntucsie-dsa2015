#!/bin/bash

echo; echo Make sure your output file of \"impressed.in\" is in this folder.
read -p "Enter your output file name: " fn
touch tmp_y.out tmp_d.out tmp_f.out
rm -f tmp_y.out tmp_d.out tmp_f.out
sort $fn > tmp_y.out
sort impressed.out > tmp_d.out
diff -b -B tmp_y.out tmp_d.out > tmp_f.out
if grep "*" tmp_f.out > /dev/null
then
	echo; echo "Sorry~ Wrong Answer Detected!"; echo
else
	echo; echo "Congratulations~ Same output!"; echo
fi
rm -f tmp_y.out tmp_d.out tmp_f.out > /dev/null

