package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	hn := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		hn[i], _ = strconv.Atoi(bs.Text())
	}

	var ans uint64
	ans = uint64(hn[0]) + 1

	for i := 1; i < n; i++ {
		if hn[i] < hn[i-1] {
			ans += uint64(hn[i-1] - hn[i])
		}
		ans++

		if hn[i] > hn[i-1] {
			ans += uint64(hn[i] - hn[i-1])
		}
		ans++
	}

	fmt.Println(ans)
}
