package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, l, r, x int
	fmt.Scan(&n, &l, &r, &x)

	cn := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&cn[i])
	}
	sort.Sort(sort.IntSlice(cn))

	ans := 0
	for s := 0; s < 1<<uint(n); s++ {
		total := 0
		min, max := -1, -1

		set := s
		cnt := 0
		for i := 0; set != 0 && i < n; i++ {
			if set&1 != 0 {
				total += cn[i]
				if min == -1 {
					min = i
				}
				cnt++
				max = i
			}
			set >>= 1
		}

		if cnt >= 2 && total <= r && total >= l && cn[max]-cn[min] >= x {
			ans++
		}
	}

	fmt.Println(ans)
}
