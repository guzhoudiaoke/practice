package main

import (
	"fmt"
)

func solve(n int, numbers []int) (a, b int) {
	left := 0
	right := n - 1
	a = 0
	b = 0
	for left <= right {
		if numbers[left] > numbers[right] {
			a += numbers[left]
			left++
		} else {
			a += numbers[right]
			right--
		}

		if left > right {
			break
		}

		if numbers[left] > numbers[right] {
			b += numbers[left]
			left++
		} else {
			b += numbers[right]
			right--
		}
	}

	return a, b
}

func main() {
	var n int
	fmt.Scan(&n)

	numbers := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&numbers[i])
	}

	fmt.Println(solve(n, numbers))
}
