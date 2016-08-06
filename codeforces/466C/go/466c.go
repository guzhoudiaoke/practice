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

	an := make([]int64, n, n)
	var sum int64 = 0
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		an[i], _ = strconv.ParseInt(bs.Text(), 10, 64)
		sum += an[i]
	}

	if sum%3 != 0 {
		fmt.Println(0)
		return
	}

	sum /= 3
	count := make([]int64, n, n)
	var s int64 = 0
	for i := n - 1; i >= 0; i-- {
		s += an[i]
		if s == sum {
			count[i] = 1
		}
	}

	for i := n - 2; i >= 0; i-- {
		count[i] += count[i+1]
	}

	s = 0
	var ans int64 = 0
	for i := 0; i < n-2; i++ {
		s += an[i]
		if s == sum {
			ans += count[i+2]
		}
	}

	fmt.Println(ans)
}
