# Create a file 'cdac.txt' and write 5 lines
echo "Bash scripting lets you automate repetitive tasks" > cdac.txt
echo "Bash scripting is incredibly versatile" >> cdac.txt
echo "Fascinating world of Bash scripting" >> cdac.txt
echo "It's just the beginning" >> cdac.txt
echo "Never say never" >> cdac.txt

# Display lines between 1 and 3
sed -n '1,3p' cdac.txt

# Append a new line 'Hello there' after line 2
sed -i '2 a Hello there' cdac.txt

