#!/bin/bash
echo "Enter a string"
read string
echo "enter start position and length of substring"
read pos len
echo "substring is ${string:$pos:$len}"
