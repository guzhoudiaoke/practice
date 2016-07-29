package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, m int
	var str string
	fmt.Scan(&str)
	fmt.Scan(&m)

	n = len(str)
	an := make([]int, n, n)

	an[0] = 0
	k := 0
	for i := 1; i < n; i++ {
		if str[i] == str[i-1] {
			k++
		}
		an[i] = k
	}

	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < m; i++ {
		bs.Scan()
		l, _ := strconv.Atoi(bs.Text())
		bs.Scan()
		r, _ := strconv.Atoi(bs.Text())
		fmt.Println(an[r-1] - an[l-1])
	}
}
