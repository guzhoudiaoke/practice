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

	first := n - an[0]
	ans := true
	for i := 1; i < n; i++ {
		if i%2 != 0 {
			an[i] -= first
			an[i] += n
		} else {
			an[i] += first
		}
		if an[i]%n != i {
			ans = false
			break
		}
	}

	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
