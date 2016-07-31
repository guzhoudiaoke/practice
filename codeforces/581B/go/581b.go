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
	ans := make([]int, n, n)

	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		hn[i], _ = strconv.Atoi(bs.Text())
	}

	h := 0
	for i := n - 1; i >= 0; i-- {
		delta := 0
		if hn[i] <= h {
			delta = h - hn[i] + 1
		}
		ans[i] = delta
		if h < hn[i] {
			h = hn[i]
		}
	}

	s := fmt.Sprint(ans)
	fmt.Println(s[1 : len(s)-1])
}
