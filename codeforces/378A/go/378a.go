package main

import (
	"fmt"
)

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	var a, b int
	fmt.Scan(&a, &b)

	who_win := make([]int, 3, 3)
	for i := 1; i <= 6; i++ {
		if abs(i-a) < abs(i-b) {
			who_win[0]++
		} else if abs(i-a) == abs(i-b) {
			who_win[1]++
		} else {
			who_win[2]++
		}
	}

	fmt.Println(who_win[0], who_win[1], who_win[2])
}
