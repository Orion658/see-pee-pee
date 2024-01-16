# Create directories and files
mkdir -p one/two/three
touch one/file1 one/file2
touch one/two/file3 one/two/file4
touch one/two/three/file5 one/two/three/file6

# Remove everything under directory 'one'
rm -r one/*
