package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	letters := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&letters[i])
	}

	ans := 0
	pre := -1
	for i := 0; i < n; i++ {
		if letters[i] == 1 {
			if pre == -1 {
				ans++
			} else {
				if i-pre == 1 {
					ans++
				} else {
					ans += 2
				}
			}
			pre = i
		}
	}

	fmt.Println(ans)
}
