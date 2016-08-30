package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	seats := make([]string, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&seats[i])
	}

	ans := -1
	line := "++"
	for i := 0; i < n; i++ {
		rs := []rune(seats[i])
		if rs[0] == 'O' && rs[1] == 'O' {
			ans = i
			line += string(rs[2:5])
			break
		}
		if rs[3] == 'O' && rs[4] == 'O' {
			ans = i
			line = string(rs[0:3]) + line
			break
		}
	}

	if ans == -1 {
		fmt.Println("NO")
	} else {
		fmt.Println("YES")
		for i := 0; i < ans; i++ {
			fmt.Println(seats[i])
		}
		fmt.Println(line)
		for i := ans + 1; i < n; i++ {
			fmt.Println(seats[i])
		}
	}
}
