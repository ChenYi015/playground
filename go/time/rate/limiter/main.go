package main

import (
	"context"
	"fmt"
	"time"

	"golang.org/x/time/rate"
)

func allowExample1() {
	fmt.Println("===== limiter.Allow Example 1 =====")
	limiter := rate.NewLimiter(rate.Limit(2), 5)
	for i := range 10 {
		if limiter.Allow() {
			fmt.Printf("%s: %d\n", time.Now().Format(time.RFC3339), i)
		}
	}
	fmt.Println("=====================")
}

func reserverExample1() {
	fmt.Println("===== limiter.Reserve Example 1 =====")
	limiter := rate.NewLimiter(rate.Limit(0.5), 5)
	for i := range 10 {
		reservation := limiter.Reserve()
		if reservation.OK() {
			time.Sleep(reservation.Delay())
			fmt.Printf("%s: %d\n", time.Now().Format(time.RFC3339), i)
		}
	}
	fmt.Println("=====================")

}

func waitExample1() {
	fmt.Println("===== limiter.Wait Example 1 =====")
	limiter := rate.NewLimiter(rate.Limit(0.5), 5)
	ctx := context.Background()
	for i := range 10 {
		if err := limiter.Wait(ctx); err != nil {
			fmt.Printf("Error occurred: %v.\n", err)
		} else {
			fmt.Printf("%s: %d\n", time.Now().Format(time.RFC3339), i)
		}
	}
	fmt.Println("=====================")
}

func main() {
	allowExample1()
	reserverExample1()
	waitExample1()
}
