package main

import (
	"fmt"
)

type Person struct {
	Name string
	Age  int
}

func modifyPersonByValue(p Person) {
	p.Name = "John Doe"
	p.Age = 30
}

func modifyPersonByPointer(p *Person) {
	p.Name = "John Doe"
	p.Age = 30
}

func (p Person) String() string {
	return fmt.Sprintf(`{"Name": "%s", "Age": %d}`, p.Name, p.Age)
}

type Data struct {
	Values []int
	Number *int
}

func modifyDataByValue(d Data) {
	d.Values[0] = -1
	*d.Number = 10
}

func modifyDataByPointer(d *Data) {
	d.Values[0] = -2
	*d.Number = 20
}

func (d Data) String() string {
	return fmt.Sprintf(`{"Values": %v, "Number": %d}`, d.Values, *d.Number)
}

func main() {
	p := Person{Name: "Alice", Age: 25}
	fmt.Println("Original:         ", p)

	modifyPersonByValue(p)
	fmt.Println("Modify by value:  ", p)

	modifyPersonByPointer(&p)
	fmt.Println("Modify by pointer:", p)

	number := 0
	d := Data{Values: []int{1, 2, 3}, Number: &number}
	fmt.Println("Original:         ", d)

	modifyDataByValue(d)
	fmt.Println("Modify by value:  ", d)

	modifyDataByPointer(&d)
	fmt.Println("Modify by pointer:", d)
}
