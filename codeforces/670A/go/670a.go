package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func solve(n int) (mmin, mmax int) {
	if n%7 == 0 {
		week := n / 7
		return week * 2, week * 2
	}

	week := n / 7
	mod := n % 7

	mmax = week*2 + min(mod, 2)
	mmin = week * 2
	if mod == 6 {
		mmin++
	}

	return mmin, mmax
}

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Println(solve(n))
}
