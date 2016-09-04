package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	ans := false
	for x := 0; a*x <= c; x++ {
		if (c-a*x)%b == 0 {
			ans = true
			break
		}
	}

	if ans {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
