package main

import "fmt"

func main() {
	var s string
	fmt.Scan(&s)

	counts := make([]int, 26, 26)
	for i := 0; i < len(s); i++ {
		counts[s[i]-'a']++
	}

	odd := 0
	for i := 0; i < 26; i++ {
		if counts[i]%2 != 0 {
			odd++
		}
	}

	if odd == 0 || odd == 1 || odd%2 == 1 {
		fmt.Println("First")
	} else {
		fmt.Println("Second")
	}
}
