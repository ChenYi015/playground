#!/usr/bin/env bash

echo "Example 1: Loop over list"
for fruit in apple banana cherry; do
    echo "Fruit: $fruit"
done

echo "Example 2: Loop over command output"
for file in $(ls); do
    echo "File: $file"
done

echo "Example 3: C-style loop"
for ((i = 0; i < 5; i++)); do
    echo "i: $i"
done

echo "Example 4: Loop over script arguments"
for arg in "$@"; do
    echo "Argument: $arg"
done
