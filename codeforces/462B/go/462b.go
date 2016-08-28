package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	cards := ""
	fmt.Scan(&cards)

	counts := make([]int, 26, 26)
	for i := 0; i < len(cards); i++ {
		counts[cards[i]-'A']++
	}

	sort.Sort(sort.Reverse(sort.IntSlice(counts)))
	var ans uint64
	ans = 0
	i := 0
	for k > 0 {
		if counts[i] < k {
			k -= counts[i]
			ans += uint64(counts[i]) * uint64(counts[i])
		} else {
			ans += uint64(k) * uint64(k)
			k = 0
		}
		i++
	}

	fmt.Println(ans)
}
