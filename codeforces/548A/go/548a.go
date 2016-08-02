package main

import (
	"fmt"
)

func check(s string, l int) bool {
	for i := 0; i < l/2; i++ {
		if s[i] != s[l-1-i] {
			return false
		}
	}

	return true
}

func solve(s string, k int) bool {
	length := len(s)
	if length%k != 0 {
		return false
	}

	d := length / k
	for i := 0; i < length; i += d {
		if !check(s[i:i+d], d) {
			return false
		}
	}

	return true
}

func main() {
	var s string
	var k int
	fmt.Scan(&s)
	fmt.Scan(&k)

	if solve(s, k) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
