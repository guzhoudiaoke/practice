package main

import (
	"fmt"
)

func solve(n int, s string) int {
	if n > 26 {
		return -1
	}

	counts := make([]int, 26, 26)
	for i := 0; i < len(s); i++ {
		counts[s[i]-'a']++
	}

	diff := 0
	for i := 0; i < 26; i++ {
		if counts[i] != 0 {
			diff++
		}
	}

	return len(s) - diff
}

func main() {
	var n int
	fmt.Scan(&n)
	var s string
	fmt.Scan(&s)

	fmt.Println(solve(n, s))
}
