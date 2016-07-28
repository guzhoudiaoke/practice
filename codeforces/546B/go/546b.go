package main

import (
	"fmt"
)

func main() {
	var n, a int
	fmt.Scan(&n)

	counts := make([]int, 2*n, 2*n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a)
		counts[a]++
	}

	next := 1
	ans := 0
	for i := 1; i <= n; i++ {
		for counts[i] > 1 {
			counts[i]--
			for next <= i || counts[next] != 0 {
				next++
			}
			ans += next - i
			counts[next]++
		}
	}

	fmt.Println(ans)
}
