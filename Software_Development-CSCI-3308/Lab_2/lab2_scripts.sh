#!/bin/bash
# Authors : Michael Rogers
# Date: 1/31/2019
# Problem 1 Code:
# Make sure to document how you are solving each problem!

echo "Enter regex command: "
# Uses read command to store user regex command.
read regcommand
echo "Enter file name: "
# Uses read command to store user file name.
read file
# Greps user command with the file name.
grep $regcommand $file

# Counts 3 digits from zero to 9 for the area code and then again for the
# first 3 digits and then again for the last 4 digits creating a full phone number.
echo "Number of Phone Numbers: "
grep -c '[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}' regex_practice.txt

# Returns every line that has an @ sign in it which classifies an email adderss
echo "Number of emails: "
grep -c "@" regex_practice.txt

# Same strategy as above except uses 303 instead of 0-9 for the first 3 digits
# and uses egrep instead of regular grep, then  writes to phone_results.
egrep "(303-[0-9]{3}-[0-9]{4})" regex_practice.txt >> phone_results.txt

# Writes every line that contains @geocities.com
grep '@geocities.com' regex_practice.txt >> email_results.txt

# greps the first command line argument into regex_practice.txt then writes
# the result to command_results.txt.
grep $1 regex_practice.txt >> command_results.txt
