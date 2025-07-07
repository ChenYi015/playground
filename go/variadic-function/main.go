package main

import "fmt"

func printArgs(args ...any) {
	fmt.Printf("%s, %s, %s\n", args...)
}

func main() {
	printArgs("a", "b", "c")

	args := []any{"a", "b", "c"}
	printArgs(args...)
}
