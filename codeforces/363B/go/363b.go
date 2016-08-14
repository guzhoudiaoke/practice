package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	hn := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		hn[i], _ = strconv.Atoi(bs.Text())
	}

	cur := 0
	for j := 0; j < k; j++ {
		cur += hn[j]
	}

	sum, ans := cur, 1
	for i := 1; i <= n-k; i++ {
		cur -= hn[i-1]
		cur += hn[i+k-1]
		if cur < sum {
			sum = cur
			ans = i + 1
		}
	}

	fmt.Println(ans)
}
