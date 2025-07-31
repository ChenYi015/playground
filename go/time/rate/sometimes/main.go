package main

import (
	"fmt"
	"time"

	"golang.org/x/time/rate"
)

func example1() {
	fmt.Println("===== Example 1 =====")
	sometimes := rate.Sometimes{
		First: 3,
	}

	for i := range 10 {
		sometimes.Do(func() {
			fmt.Printf("%d\n", i)
		})
	}
	// Output:
	// 0
	// 1
	// 2
	fmt.Println("=====================")
}

func example2() {
	fmt.Println("===== Example 2 =====")
	sometimes := rate.Sometimes{
		Every: 2,
	}

	for i := range 10 {
		sometimes.Do(func() {
			fmt.Printf("%d\n", i)
		})
	}
	// Output:
	// 0
	// 2
	// 4
	// 6
	// 8
	fmt.Println("=====================")
}

func example3() {
	fmt.Println("===== Example 3 =====")
	sometimes := rate.Sometimes{
		First: 3,
		Every: 2,
	}

	for i := range 10 {
		sometimes.Do(func() {
			fmt.Printf("%d\n", i)
		})
	}
	// Output:
	// 0
	// 1
	// 2
	// 4
	// 6
	// 8
	fmt.Println("=====================")
}

func example4() {
	fmt.Println("===== Example 4 =====")
	sometimes := rate.Sometimes{
		Interval: time.Second * 1,
	}

	for i := range 10 {
		sometimes.Do(func() {
			fmt.Printf("%d\n", i)
		})
		time.Sleep(time.Millisecond * 500)
	}
	// Output:
	// 0
	// 2
	// 4
	// 6
	// 8
	fmt.Println("=====================")
}

func example5() {
	fmt.Println("===== Example 5 =====")
	sometimes := rate.Sometimes{
		First:    2,
		Every:    3,
		Interval: time.Second * 1,
	}

	for i := range 10 {
		sometimes.Do(func() {
			fmt.Printf("%d\n", i)
		})
		time.Sleep(time.Millisecond * 500)
	}
	// Output:
	// 0
	// 1
	// 3
	// 5
	// 6
	// 8
	// 9
	fmt.Println("=====================")
}

func main() {
	example1()
	example2()
	example3()
	example4()
	example5()
}
