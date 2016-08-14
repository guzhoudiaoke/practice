package main

import (
	"fmt"
)

func main() {
	var n, bx int
	fmt.Scan(&n, &bx)

	var x, dx uint64
	for i := 0; i < n; i++ {
		fmt.Scan(&dx)
		x = x*uint64(bx) + dx
	}

	var m, by int
	fmt.Scan(&m, &by)

	var y, dy uint64
	for i := 0; i < m; i++ {
		fmt.Scan(&dy)
		y = y*uint64(by) + dy
	}

	if x < y {
		fmt.Println("<")
	} else if x > y {
		fmt.Println(">")
	} else {
		fmt.Println("=")
	}
}
