package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n, n)
	sum := 0
	for i := 0; i < n; i++ {
		fmt.Scan(&an[i])
		sum += an[i]
	}

	visited := make([]bool, n, n)
	index := 0
	wanted := sum * 2 / n
	for i := 0; i < n/2; i++ {
		for ; index < n && visited[index]; index++ {
		}

		j := index + 1
		for ; j < n; j++ {
			if !visited[j] && an[index]+an[j] == wanted {
				break
			}
		}

		visited[index] = true
		visited[j] = true
		fmt.Println(index+1, j+1)
	}
}
