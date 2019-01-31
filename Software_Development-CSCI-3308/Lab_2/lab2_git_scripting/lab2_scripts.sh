#!/bin/bash
# Authors : Michael Rogers
# Date: 1/31/2019
#Problem 1 Code:
#Make sure to document how you are solving each problem!
echo "Enter regex command: "
read regcommand
echo "Enter file name: "
read file
grep $regcommand $file
grep
