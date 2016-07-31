package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	cur := 1
	for i := 0; i < n; i++ {
		for j := 0; j < n/2; j++ {
			fmt.Printf("%d %d ", cur, n*n-cur+1)
			cur++
		}
		fmt.Println()
	}
}
