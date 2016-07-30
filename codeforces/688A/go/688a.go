package main

import (
	"fmt"
	"strings"
)

func main() {
	var n, d int
	fmt.Scan(&n, &d)

	var s string
	days := 0
	max := 0
	for i := 0; i < d; i++ {
		fmt.Scan(&s)
		if strings.Count(s, "1") < n {
			days++
			if days > max {
				max = days
			}
		} else {
			days = 0
		}
	}

	fmt.Println(max)
}
