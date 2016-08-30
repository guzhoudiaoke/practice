package main

import (
	"fmt"
	"sort"
)

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&an[i])
	}

	sort.Sort(sort.Reverse(sort.IntSlice(an)))

	var ans uint64
	ans = uint64(an[0])
	pre := an[0]
	for i := 1; i < n; i++ {
		cur := min(pre-1, an[i])
		if cur == 0 {
			break
		}
		pre = cur
		ans += uint64(cur)
	}
	fmt.Println(ans)
}
