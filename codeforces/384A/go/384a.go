package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	even := ""
	for i := 0; i < n; i++ {
		if i%2 == 0 {
			even += "C"
		} else {
			even += "."
		}
	}
	odd := even[1:n]
	if n%2 == 0 {
		odd += "C"
	} else {
		odd += "."
	}

	if n%2 == 0 {
		fmt.Println(n * n / 2)
	} else {
		fmt.Println((n*n + 1) / 2)
	}

	for i := 0; i < n; i++ {
		if i%2 == 0 {
			fmt.Println(even)
		} else {
			fmt.Println(odd)
		}
	}
}
