package main

import (
	"fmt"
)

func check(c1, c2, c3, c4 byte) bool {
	counts := make([]int, 26, 26)
	counts[c1-'a']++
	counts[c2-'a']++
	counts[c3-'a']++
	counts[c4-'a']++

	return counts['f'-'a'] == 1 && counts['a'-'a'] == 1 && counts['c'-'a'] == 1 && counts['e'-'a'] == 1
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	image := make([]string, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&image[i])
	}

	ans := 0
	for i := 0; i < n-1; i++ {
		for j := 0; j < m-1; j++ {
			if check(image[i][j], image[i+1][j], image[i][j+1], image[i+1][j+1]) {
				ans++
			}
		}
	}

	fmt.Println(ans)
}
