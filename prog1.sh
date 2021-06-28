#!/bin/bash
echo "enter file name"
read file
if [ -e $file ]
then
if [ -f $file ]
then
echo "${file} is a regular file"
elif [ -d $file ]
then
echo "${file} is a directory"
elif [ -l $file ]
then
echo "${file} is a symbolic link file"
elif [ -b $file ]
then
echo "${file} is a Block device file"
elif [ -c $file ]
then
echo "${file} is a Character device file"
else
echo "None of the above"
fi
else
echo "File does not exists"
fi
