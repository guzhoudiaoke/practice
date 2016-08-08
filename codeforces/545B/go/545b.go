package main

import (
	"fmt"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	p := make([]byte, len(s), len(s))

	dis := 0
	cur := 0
	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			dis++
			if cur%2 == 0 {
				p[i] = s[i]
			} else {
				p[i] = t[i]
			}
			cur++
		} else {
			p[i] = s[i]
		}
	}

	if dis%2 == 0 {
		fmt.Println(string(p))
	} else {
		fmt.Println("impossible")
	}
}
