#!/bin/bash

URL=https://github.com/NTUDSA2014/

echo
echo Make sure that only your source codes are in the current folder. If not, press CTRL+C to quit.
read -p "Please enter your hashID of dsa2015 (ex: dsa15_096): " id
read -p "Which hw are this commit for(ex: hw3)? " hw
URL=$URL$id".git"

rm toGithub -rf
mkdir toGithub

cd toGithub
git init
git remote add origin $URL
git pull origin master
rm -rf $hw
mkdir $hw
cd ..

cp *.cpp ./toGithub/$hw/
cp *.c ./toGithub/$hw/
cp *.h ./toGithub/$hw/
cp *akefile ./toGithub/$hw/

cd toGithub
git add $hw
git commit -m hw_for_dsa
git push origin master

git tag -d $hw
git push origin :$hw
git tag -a $hw -m hw_for_dsa
git push origin $hw
cd ..

rm toGithub -rf

