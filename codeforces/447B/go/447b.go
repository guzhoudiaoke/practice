package main

import (
	"fmt"
)

func main() {
	s := ""
	fmt.Scan(&s)

	k := 0
	fmt.Scan(&k)

	w := make([]int, 26, 26)
	m := 0
	for i := 0; i < 26; i++ {
		fmt.Scan(&w[i])
		if m < w[i] {
			m = w[i]
		}
	}

	ans := 0
	for i := 0; i < len(s); i++ {
		ans += (i + 1) * w[int(s[i]-'a')]
	}
	for i := 0; i < k; i++ {
		ans += m * (len(s) + i + 1)
	}

	fmt.Println(ans)
}
