package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	tn := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		tn[i], _ = strconv.Atoi(bs.Text())
	}

	sort.Ints(tn)
	ans := n
	var wait int64 = 0
	for i := 0; i < n; i++ {
		if int64(tn[i]) < wait {
			ans--
		} else {
			wait += int64(tn[i])
		}
	}

	fmt.Println(ans)
}
