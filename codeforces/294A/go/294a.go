package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&an[i])
	}

	var m int
	fmt.Scan(&m)

	var x, y int
	for i := 0; i < m; i++ {
		fmt.Scan(&x, &y)
		if x <= n-1 {
			an[x] += an[x-1] - y
		}
		if x > 1 {
			an[x-2] += y - 1
		}
		an[x-1] = 0
	}

	for i := 0; i < n; i++ {
		fmt.Println(an[i])
	}
}
