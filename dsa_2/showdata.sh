#!/bin/bash

cd /tmp2/KDDCup2012/track2/
#read -p "lines to read: " t
#head kddcup2012track2.txt -n $t | grep -n --color=auto "^1"
#head kddcup2012track2.txt -n $t | grep --color=auto "^1.*55984$" | awk 'BEGIN{FS="\t"};{print $12 " " $4 " " $8}'
head kddcup2012track2.txt -n 1200 | grep -n --color=auto "55984$" | grep --color=auto "^1017:" 
head kddcup2012track2.txt -n 1200 | grep -n --color=auto "55984$" | grep --color=auto "^1028:" 
head kddcup2012track2.txt -n 2000 | grep -n --color=auto "[[:blank:]]21162514[[:blank:]]" | awk 'BEGIN{FS="\t"};{print $4 " " $3 " " $5 " " $9 " " $10 " " $11}'
tail kddcup2012track2.txt -n 1 | awk 'BEGIN{FS="\t"};{print $12 " " $4 " " $8 " " $7 " " $6 " : " $1 " " $2}'
cd

