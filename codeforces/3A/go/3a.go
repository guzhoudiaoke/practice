package main

import (
	"fmt"
)

func distance(x, y byte) byte {
	if x > y {
		return x - y
	}
	return y - x
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func abs(x int) int {
	if x > 0 {
		return x
	}
	return -x
}

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	dx := int(distance(t[0], s[0]))
	dy := int(distance(t[1], s[1]))

	ans := min(dx, dy) + abs(dx-dy)
	fmt.Println(ans)

	mov := ""
	if t[0] > s[0] {
		mov += "R"
	} else {
		mov += "L"
	}
	if t[1] < s[1] {
		mov += "D"
	} else {
		mov += "U"
	}

	i := 0
	for ; i < min(dx, dy); i++ {
		fmt.Println(mov)
	}
	for ; i < ans; i++ {
		if dx > dy {
			fmt.Println(string(mov[0]))
		} else {
			fmt.Println(string(mov[1]))
		}
	}
}
