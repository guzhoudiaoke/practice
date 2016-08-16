package main

import (
	"fmt"
)

func solve(k int, s string) string {
	length := len(s)
	if length%k != 0 {
		return "-1"
	}

	counts := make([]int, 26, 26)
	for i := 0; i < length; i++ {
		counts[s[i]-'a']++
	}

	tmp := ""
	for i := 0; i < 26; i++ {
		if counts[i] == 0 {
			continue
		}
		if counts[i]%k != 0 {
			return "-1"
		}
		for j := 0; j < counts[i]/k; j++ {
			tmp += string(i + 'a')
		}
	}

	ans := ""
	for i := 0; i < length/len(tmp); i++ {
		ans += tmp
	}

	return ans
}

func main() {
	var k int
	fmt.Scan(&k)

	var s string
	fmt.Scan(&s)

	fmt.Println(solve(k, s))
}
