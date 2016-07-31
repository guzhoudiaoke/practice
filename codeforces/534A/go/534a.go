package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	if n == 1 || n == 2 {
		fmt.Println("1")
		fmt.Println("1")
	} else if n == 3 {
		fmt.Println("2")
		fmt.Println("1 3")
	} else {
		fmt.Println(n)

		odd := n - 1
		even := n
		if n%2 != 0 {
			odd = n
			even = n - 1
		}
		for i := odd; i >= 1; i -= 2 {
			fmt.Printf("%d ", i)
		}
		for i := even; i >= 2; i -= 2 {
			fmt.Printf("%d ", i)
		}
		fmt.Println()
	}
}
