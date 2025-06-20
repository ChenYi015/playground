package main

import (
	"fmt"
	"log"

	"example.com/playground/version"
	"github.com/spf13/cobra"
)

func NewCommand() *cobra.Command {
	var (
		debug    bool
		integer  int
		integers []int
		number   float64
		numbers  []float64
		name     string
		names    []string
	)

	cmd := &cobra.Command{
		Use:   "app",
		Short: "A sample app.",
		Long:  "A sample app for learning how to use cobra.",
		RunE: func(cmd *cobra.Command, args []string) error {
			fmt.Printf("debug: %v\n", debug)
			fmt.Printf("integer: %d\n", integer)
			fmt.Printf("integers: %v\n", integers)
			fmt.Printf("number: %f\n", number)
			fmt.Printf("numbers: %v\n", numbers)
			fmt.Printf("name: %s\n", name)
			fmt.Printf("names: %v\n", names)
			return nil
		},
	}

	cmd.Flags().BoolVar(&debug, "debug", false, "Enable debug mode.")
	cmd.Flags().IntVar(&integer, "integer", 42, "An integer flag.")
	cmd.Flags().IntSliceVar(&integers, "integers", []int{1, 2, 3}, "An integer slice flag.")
	cmd.Flags().Float64Var(&number, "number", 3.14, "A float flag.")
	cmd.Flags().Float64SliceVar(&numbers, "numbers", []float64{3.14159, 2.71828}, "A float array flag.")
	cmd.Flags().StringVar(&name, "name", "World", "A string flag.")
	cmd.Flags().StringSliceVar(&names, "names", []string{"Alice", "Bob"}, "A string array flag.")

	cmd.AddCommand(version.NewCommand())

	return cmd
}

func main() {
	if err := NewCommand().Execute(); err != nil {
		log.Fatalf("Error: %v", err)
	}
}
