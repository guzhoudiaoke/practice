package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	ans := 0
	for i := 0; i < n; i++ {
		m, c := 0, 0
		fmt.Scan(&m, &c)
		if m > c {
			ans++
		} else if c > m {
			ans--
		}
	}

	if ans > 0 {
		fmt.Println("Mishka")
	} else if ans < 0 {
		fmt.Println("Chris")
	} else {
		fmt.Println("Friendship is magic!^^")
	}
}
