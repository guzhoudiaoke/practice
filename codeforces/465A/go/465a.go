package main

import (
	"fmt"
)

func solve(n int, s string) int {
	ans := 0
	for i := 0; i < n; i++ {
		ans++
		if s[i] == '0' {
			break
		}
	}
	return ans
}

func main() {
	var n int
	var s string
	fmt.Scan(&n)
	fmt.Scan(&s)

	fmt.Println(solve(n, s))
}
