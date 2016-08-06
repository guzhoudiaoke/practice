package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var keys [26]int
	rooms := ""
	fmt.Scan(&rooms)

	ans := 0
	for i := 0; i < len(rooms); i += 2 {
		keys[rooms[i]-'a']++
		if keys[rooms[i+1]-'A'] == 0 {
			ans++
		} else {
			keys[rooms[i+1]-'A']--
		}
	}

	fmt.Println(ans)
}
