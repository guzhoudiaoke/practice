package main

import (
	"fmt"
)

func main() {
	var n, m, k, a int
	fmt.Scan(&n, &m, &k)

	first := 0
	second := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		if a == 1 {
			first++
		} else {
			second++
		}
	}
	ans := 0
	if m < first {
		ans += first - m
	} else {
		k += m - first
	}

	if k < second {
		ans += second - k
	}

	fmt.Println(ans)
}
