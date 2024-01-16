#!/bin/bash

# Accept Sales and Cost from the user
read -p "Enter Sales: " sales
read -p "Enter Cost: " cost

# Calculate Profit
profit=$((sales - cost))

# Subtract 10% from Profit as Taxes
taxes=$((profit / 10))

# Calculate Net Profit
net_profit=$((profit - taxes))

# Display final amount as Net Profit
echo "Net Profit: $net_profit"
