package main

import (
	"fmt"
)

func main() {
	line := ""
	fmt.Scan(&line)

	length := len(line)
	rm := 0
	for rm = 0; rm < length; rm++ {
		if line[rm] == '0' {
			break
		}
	}

	/* all '1' */
	if rm == length {
		fmt.Println(line[1:length])
	} else {
		ans := line[0:rm] + line[rm+1:length]
		fmt.Println(ans)
	}
}
