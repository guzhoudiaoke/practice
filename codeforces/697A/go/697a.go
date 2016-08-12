package main

import (
	"fmt"
)

func solve(t, s, x int) bool {
	if x < t {
		return false
	}

	delta := x - t
	return (delta%s) == 0 || (delta/s >= 1 && delta%s == 1)
	return true
}

func main() {
	var t, s, x int
	fmt.Scan(&t, &s, &x)
	if solve(t, s, x) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
