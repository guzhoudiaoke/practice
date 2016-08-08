package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	fn := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&fn[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(fn)))

	ans := 0
	for i := 0; i < n; i += k {
		ans += 2 * (fn[i] - 1)
	}

	fmt.Println(ans)
}
