package main

import "fmt"

func main() {
	var push [3][3]int
	var grid [3][3]int
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scan(&push[i][j])
			grid[i][j] = 1
			push[i][j] = push[i][j] % 2
		}
	}

	moves := [4][2]int{{0, -1}, {0, 1}, {-1, 0}, {1, 0}}
	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			if push[i][j] == 0 {
				continue
			}

			grid[i][j] = 1 - grid[i][j]
			for k := 0; k < 4; k++ {
				x := i + moves[k][0]
				y := j + moves[k][1]
				if x >= 0 && x < 3 && y >= 0 && y < 3 {
					grid[x][y] = 1 - grid[x][y]
				}
			}
		}
	}

	for i := 0; i < 3; i++ {
		for j := 0; j < 3; j++ {
			fmt.Print(grid[i][j])
		}
		fmt.Println()
	}
}
