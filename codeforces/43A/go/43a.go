package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	first := ""
	score := 1
	fmt.Scan(&first)

	team := ""
	secon := ""
	for i := 0; i < n-1; i++ {
		fmt.Scan(&team)
		if team == first {
			score++
		} else {
			score--
			if len(second) == 0 {
				second = team
			}
		}
	}

	if score > 0 {
		fmt.Println(first)
	} else {
		fmt.Println(second)
	}
}
