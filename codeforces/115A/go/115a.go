package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	pn := make([]int, n+1, n+1)
	for i := 0; i < n; i++ {
		fmt.Scan(&pn[i])
	}

	ans := 0
	for i := 0; i < n; i++ {
		depth := 1
		cur := pn[i]
		for cur != -1 {
			cur = pn[cur-1]
			depth++
		}

		if ans < depth {
			ans = depth
		}
	}

	fmt.Println(ans)
}
