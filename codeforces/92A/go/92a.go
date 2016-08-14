package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	sums := make([]int, n+1, n+1)
	for i := 1; i <= n; i++ {
		sums[i] = i + sums[i-1]
	}

	if m >= sums[n] {
		m %= sums[n]
	}

	for i := 1; i <= n; i++ {
		if m < sums[i] {
			m -= sums[i-1]
			break
		}
	}

	fmt.Println(m)
}
