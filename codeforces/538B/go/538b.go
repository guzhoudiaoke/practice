package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	k := 0
	ans := ""
	for n != 0 {
		cur := n
		m := 0
		p := 1
		for cur != 0 {
			if cur%10 != 0 {
				m += p
			}
			p *= 10
			cur /= 10
		}

		k++
		n -= m
		ans += strconv.Itoa(m)
		ans += " "
	}

	fmt.Println(k)
	fmt.Println(ans)
}
