package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type range_s struct {
	a int
	b int
}

func main() {
	var t, k int
	fmt.Scan(&t, &k)

	ranges := make([]range_s, t, t)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)

	max := 0
	for i := 0; i < t; i++ {
		bs.Scan()
		ranges[i].a, _ = strconv.Atoi(bs.Text())

		bs.Scan()
		ranges[i].b, _ = strconv.Atoi(bs.Text())

		if ranges[i].b > max {
			max = ranges[i].b
		}
	}

	// eg, k = 2
	// when len >= k, if last==R, pre i-1 can be R/W, if last==W, pre should have k-1 W
	// len1: R
	// len2: RR, WW -- last_R + last_W = dp[i-1] + dp[i-k]
	var modulo uint64
	modulo = 1000000007
	dp := make([]uint64, max+1, max+1)
	for i := 0; i < k; i++ {
		dp[i] = 1
	}
	for i := k; i <= max; i++ {
		dp[i] = (dp[i-1] + dp[i-k]) % modulo
	}

	for i := 1; i <= max; i++ {
		dp[i] = (dp[i] + dp[i-1]) % modulo
	}

	for i := 0; i < t; i++ {
		ans := (dp[ranges[i].b] - dp[ranges[i].a-1] + modulo) % modulo
		fmt.Println(ans)
	}
}
