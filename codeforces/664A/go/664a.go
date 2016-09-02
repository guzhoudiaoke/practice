package main

import "fmt"

func main() {
	var a, b string
	fmt.Scan(&a, &b)

	if a == b {
		fmt.Println(a)
	} else {
		fmt.Println(1)
	}
}
