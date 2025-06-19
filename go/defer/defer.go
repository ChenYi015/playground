package main

import "fmt"

func sayHello(name string) {
	fmt.Printf("Hello, %s!\n", name)
}

func sayGoodbye(name string) {
	fmt.Printf("Goodbye, %s!\n", name)
}

func main() {
	name := "World"
	defer sayGoodbye(name)
	sayHello(name)
}