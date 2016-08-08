package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	dn := make([]int, n, n)
	total := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&dn[i])
		total += dn[i]
	}

	var s, t int
	fmt.Scan(&s, &t)
	ans := 0
	if s > t {
		s, t = t, s
	}
	for i := s - 1; i < t-1; i++ {
		ans += dn[i]
	}

	if ans > total-ans {
		ans = total - ans
	}

	fmt.Println(ans)
}
