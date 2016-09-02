package main

import (
	"fmt"
)

func solve(s, t string) string {
	// atomaton
	first := 0
	second := 0

	for ; first < len(s); first++ {
		if s[first] == t[second] {
			second++
		}
		if second == len(t) {
			break
		}
	}

	if second == len(t) && first <= len(s) {
		return "automaton"
	}

	// counts
	count_s := make([]int, 26, 26)
	count_t := make([]int, 26, 26)
	for i := 0; i < len(s); i++ {
		count_s[s[i]-'a']++
	}
	for i := 0; i < len(t); i++ {
		count_t[t[i]-'a']++
	}

	// array
	array := true
	for i := 0; i < 26; i++ {
		if count_t[i] != count_s[i] {
			array = false
			break
		}
	}
	if array {
		return "array"
	}

	// both
	both := true
	for i := 0; i < 26; i++ {
		if count_t[i] > count_s[i] {
			both = false
			break
		}
	}
	if both {
		return "both"
	}

	return "need tree"
}

func main() {
	var s, t string
	fmt.Scan(&s)
	fmt.Scan(&t)

	fmt.Println(solve(s, t))
}
