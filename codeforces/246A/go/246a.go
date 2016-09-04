package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	if n <= 2 {
		fmt.Println(-1)
	} else {
		for i := n; i > 0; i-- {
			fmt.Print(i, " ")
		}
		fmt.Println()
	}
}
