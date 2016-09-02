package main

import "fmt"

func main() {
	var pos string
	fmt.Scan(&pos)

	ans := 8
	if pos == "a8" || pos == "h8" || pos == "a1" || pos == "h1" {
		ans = 3
	} else {
		if pos[0] == 'a' || pos[0] == 'h' || pos[1] == '1' || pos[1] == '8' {
			ans = 5
		}
	}

	fmt.Println(ans)
}
