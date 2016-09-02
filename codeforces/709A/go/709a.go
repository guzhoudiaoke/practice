package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, b, d int
	fmt.Scan(&n, &b, &d)

	an := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)

	for i := 0; i < n; i++ {
		bs.Scan()
		an[i], _ = strconv.Atoi(bs.Text())
	}

	ans := 0
	cur := 0
	for i := 0; i < n; i++ {
		if an[i] > b {
			continue
		}
		cur += an[i]
		if cur > d {
			cur = 0
			ans++
		}
	}

	fmt.Println(ans)
}
