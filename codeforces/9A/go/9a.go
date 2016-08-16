package main

import (
	"fmt"
)

func main() {
	var y, w int
	fmt.Scan(&y, &w)

	m := y
	if w > m {
		m = w
	}

	ans := 0
	for i := 1; i <= 6; i++ {
		if i >= m {
			ans++
		}
	}

	var strs = [6]string{"1/6", "1/3", "1/2", "2/3", "5/6", "1/1"}
	fmt.Println(strs[ans-1])
}
