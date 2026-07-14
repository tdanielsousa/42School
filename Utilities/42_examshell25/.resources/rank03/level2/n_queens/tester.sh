#!/bin/bash
source ../../../main/colors.sh

rendu_dir="../../../../rendu/n_queens"

# Check directory
if [ ! -d "$rendu_dir" ]; then
    echo "FAIL: Directory not found"
    exit 1
fi

# Find files
c_files=$(find "$rendu_dir" -name "*.c")
if [ -z "$c_files" ]; then
    echo "FAIL: No .c files"
    exit 1
fi

# Compile FIRST
echo "Compiling..."
gcc -Wall -Wextra -Werror -o n_queens_test $c_files
if [ $? -ne 0 ]; then
    echo "FAIL: Compilation error"
    exit 1
fi

# ---------------- TESTS ----------------

echo "Testing n=4..."
./n_queens_test 4 > out.txt
lines=$(wc -l < out.txt)

if [ "$lines" -ne 2 ]; then
    echo "FAIL: n=4 expected 2 solutions, got $lines"
    cat out.txt
    exit 1
fi

# Check exact solutions
sort out.txt > sorted.txt
echo -e "1 3 0 2\n2 0 3 1" | sort > expected.txt

if ! diff sorted.txt expected.txt >/dev/null; then
    echo "FAIL: wrong solutions"
    echo "Expected:"
    cat expected.txt
    echo "Got:"
    cat sorted.txt
    exit 1
fi

echo "Testing n=2..."
./n_queens_test 2 > out.txt
[ $(wc -l < out.txt) -ne 0 ] && echo "FAIL n=2" && exit 1

echo "Testing n=3..."
./n_queens_test 3 > out.txt
[ $(wc -l < out.txt) -ne 0 ] && echo "FAIL n=3" && exit 1

echo "Testing n=8..."
./n_queens_test 8 > out.txt
[ $(wc -l < out.txt) -ne 92 ] && echo "FAIL n=8" && exit 1

echo "PASSED 🎉"
