# Create a file 'cdac.txt' and write 5 lines
echo "Bash scripting lets you automate repetitive tasks" > cdac.txt
echo "Bash scripting is incredibly versatile" >> cdac.txt
echo "Fascinating world of Bash scripting" >> cdac.txt
echo "It's just the beginning" >> cdac.txt
echo "Never say never" >> cdac.txt

# Count number of characters, words, and lines in the file
wc cdac.txt

# character
echo -n "characters: "
wc -m cdac.txt

# words
echo -n "words: "
wc -w cdac.txt

#lines
echo -n "lines: "
wc -l cdac.txt
