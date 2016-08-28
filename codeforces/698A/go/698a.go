package main

import "fmt"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n+1, n+1)
	for i := 1; i <= n; i++ {
		fmt.Scan(&an[i])
	}

	var dp [101][4]int
	for i := 0; i < 101; i++ {
		for j := 0; j < 4; j++ {
			if i != 0 {
				dp[i][j] = 101
			} else {
				dp[i][j] = 0
			}
		}
	}

	// 0: rest, 1: sport, 3: contest
	for i := 1; i <= n; i++ {
		// today do 0, the day before can do 0/1/2
		dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1

		// today do 1, the day before can't do 1
		if an[i] == 1 || an[i] == 3 {
			dp[i][1] = min(dp[i-1][0], dp[i-1][2])
		}

		// today do 2, the day before can't do 2
		if an[i] == 2 || an[i] == 3 {
			dp[i][2] = min(dp[i-1][0], dp[i-1][1])
		}
	}

	ans := min(dp[n][0], min(dp[n][1], dp[n][2]))
	fmt.Println(ans)
}
