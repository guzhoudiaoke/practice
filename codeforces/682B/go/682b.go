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

	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	an := make([]int, n, n)
	for i := 0; i < n; i++ {
		bs.Scan()
		an[i], _ = strconv.Atoi(bs.Text())
	}

	sort.Sort(sort.IntSlice(an))
	cur := 1
	for i := 0; i < n; i++ {
		if cur <= an[i] {
			cur++
		}
	}

	fmt.Println(cur)
}
