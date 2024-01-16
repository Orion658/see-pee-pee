#!/bin/bash

# Accept three numbers from the user
read -p "Enter first number: " num1
read -p "Enter second number: " num2
read -p "Enter third number: " num3

# Calculate average
average=$(( (num1 + num2 + num3) / 3 ))

# Display the average
echo "Average: $average"
