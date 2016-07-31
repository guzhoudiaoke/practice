package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&an[i])
	}

	beg := 0
	for ; beg < n && an[beg] == 0; beg++ {
	}
	end := n - 1
	for ; end >= 0 && an[end] == 0; end-- {
	}

	ans := 0
	if beg == n {
		/* all 0 */
		ans = 0
	} else if end < 0 {
		/* all 1 */
		ans = n
	} else {
		for i := beg; i <= end; i++ {
			if an[i] == 1 {
				ans++
			} else {
				left := (i == 0 || an[i-1] == 1)
				right := (i == n-1 || an[i+1] == 1)
				if left && right {
					ans++
				}
			}
		}
	}

	fmt.Println(ans)
}
