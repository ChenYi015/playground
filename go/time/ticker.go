package main

import (
	"context"
	"fmt"
	"os"
	"os/signal"
	"syscall"
	"time"
)

func main() {
	ticker := time.NewTicker(1 * time.Second)
	ctx, cancel := context.WithCancel(context.Background())

	go func() {
		sigCh := make(chan os.Signal, 1)
		signal.Notify(sigCh, syscall.SIGINT, syscall.SIGTERM)
		<-sigCh
		cancel()
	}()

	for {
		select {
		case <-ctx.Done():
			fmt.Println("Context canceled.")
			return
		case now := <-ticker.C:
			fmt.Println(now.Format(time.RFC3339))
		}
	}
}
