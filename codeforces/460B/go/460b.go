package main

import (
	"fmt"
)

func pow(x, y int) uint64 {
	var ans uint64
	ans = 1
	for i := 0; i < y; i++ {
		ans *= uint64(x)
	}
	return ans
}

func calc_s(x uint64) uint64 {
	var ans uint64
	ans = 0
	for x != 0 {
		ans += x % 10
		x /= 10
	}
	return ans
}

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	ans := make([]int, 81, 81)
	i := 0
	for s := 1; s <= 81; s++ {
		var x uint64
		x = uint64(b)*pow(s, a) + uint64(c)
		if x < uint64(1000000000) && uint64(s) == calc_s(x) {
			ans[i] = int(x)
			i++
		}
	}

	fmt.Println(i)
	if i > 0 {
		for j := 0; j < i; j++ {
			fmt.Print(ans[j], " ")
		}
		fmt.Println()
	}
}
