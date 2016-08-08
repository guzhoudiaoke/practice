package main

import (
	"fmt"
)

func get_lucky_digits_num(num string) int {
	ret := 0
	for i := 0; i < len(num); i++ {
		if num[i] == '4' || num[i] == '7' {
			ret++
		}
	}

	return ret
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var num string
	ans := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&num)
		if get_lucky_digits_num(num) <= k {
			ans++
		}
	}

	fmt.Println(ans)
}
