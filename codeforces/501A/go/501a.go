package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)

	misha := max(3*a/10, a-a/250*c)
	vasya := max(3*b/10, b-b/250*d)

	if misha > vasya {
		fmt.Println("Misha")
	} else if misha < vasya {
		fmt.Println("Vasya")
	} else {
		fmt.Println("Tie")
	}
}
