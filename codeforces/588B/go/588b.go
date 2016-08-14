package main

import (
	"fmt"
)

func main() {
	var n uint64
	fmt.Scan(&n)

	var i, ans uint64
	i = 2
	ans = 1
	for i*i <= n {
		if n%i == 0 {
			ans *= i
			for n%i == 0 {
				n /= i
			}
		}
		i++
	}

	if n > 1 {
		ans *= n
	}
	fmt.Println(ans)
}
