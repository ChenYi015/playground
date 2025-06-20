package version

import (
	"fmt"

	"github.com/spf13/cobra"
)

const (
	Version = "v0.1.0"
)

func NewCommand() *cobra.Command {
	cmd := &cobra.Command{
		Use:   "version",
		Short: "Print the version of the app.",
		RunE: func(cmd *cobra.Command, args []string) error {
			fmt.Printf("Version: %s\n", Version)
			return nil
		},
	}

	return cmd
}
