#!/bin/bash

echo "Enter the file name"
read file1


echo "Enter the permission of the file in rwxrwxrwx format"
read string 

ls -lR $file1

ls -lR $file1 | cut -b 2-1000 | grep $string
