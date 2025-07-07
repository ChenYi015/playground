package main

/*
#include "hello.h"
*/
import "C"

func main() {
	name := C.CString("World")
	C.say_hello(name)
}
