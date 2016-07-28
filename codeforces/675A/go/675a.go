package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	can := false
	if c == 0 {
		if a == b {
			can = true
		}
	} else {
		delta := b - a
		if delta == 0 {
			can = true
		} else if (delta < 0 && c < 0) || (delta > 0 && c > 0) {
			if delta%c == 0 {
				can = true
			}
		}
	}

	if can {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
