package main

/*
#include <stdio.h>

void say_hello(const char *name) {
    printf("Hello, %s!\n", name);
}
*/
import "C"

func main() {
	name := C.CString("World")
	C.say_hello(name)
}
