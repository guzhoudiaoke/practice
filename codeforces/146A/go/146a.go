package main

import (
	"fmt"
)

func is_lucky(n int, num string) bool {
	half := 0
	total := 0
	for i := 0; i < n; i++ {
		if num[i] != '4' && num[i] != '7' {
			return false
		}

		if i < n/2 {
			half += int(num[i] - '0')
		}
		total += int(num[i] - '0')
	}

	return half == total-half
}

func main() {
	var n int
	fmt.Scan(&n)

	var num string
	fmt.Scan(&num)

	if is_lucky(n, num) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
