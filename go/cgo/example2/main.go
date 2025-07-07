package main

/*
#include <stdio.h>

void hello() {
    printf("Hello, World!\n");
}
*/
import "C"

func main() {
	C.hello()
}
