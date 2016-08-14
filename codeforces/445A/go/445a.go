package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	board := make([]string, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&board[i])
	}

	for i := 0; i < n; i++ {
		line := []byte(board[i])
		for j := 0; j < m; j++ {
			if line[j] == '.' {
				if i%2 == 0 {
					if j%2 == 0 {
						line[j] = 'B'
					} else {
						line[j] = 'W'
					}
				} else {
					if j%2 == 0 {
						line[j] = 'W'
					} else {
						line[j] = 'B'
					}
				}
			}
		}

		fmt.Println(string(line))
	}
}
