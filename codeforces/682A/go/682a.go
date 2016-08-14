package main

import (
	"fmt"
)

func calc(n, k int) int {
	ret := n / 5
	for i := 1; i <= n%5; i++ {
		if (i+k)%5 == 0 {
			ret++
		}
	}
	return ret
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	pn := make([]int, 6, 6)
	sum := 0
	for i := 1; i <= 5; i++ {
		pn[i] = calc(n, i)
		sum += pn[i]
	}

	var ans int64
	ans = int64(sum) * int64(m/5)
	for i := 1; i <= m%5; i++ {
		ans += int64(pn[i])
	}

	fmt.Println(ans)
}
