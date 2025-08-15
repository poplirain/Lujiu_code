#!/bin/bash ./shell_dirop2
touch ./shell_dirop2
touch file{1..3}.txt
echo "Hello" > file1.txt
echo "World" > file2.txt
echo "THAT IS MY MAN" > file3.txt
echo "file3:"
cat file3.txt
cat >> file3.txt << EOF
new add:
HEY
YO
WHAT UP
EOF
echo "file3:"
cat file3.txt

touch combine.txt
cat file1.txt file2.txt > combine.txt
echo "file1:"
cat file1.txt
echo "file2:"
cat file2.txt
echo "combine:"
cat combine.txt

