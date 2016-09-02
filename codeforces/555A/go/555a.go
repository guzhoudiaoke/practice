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

	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)

	l := 0
	for i := 0; i < k; i++ {
		bs.Scan()
		m, _ := strconv.Atoi(bs.Text())

		first := 1
		for ; m > 0; m-- {
			bs.Scan()
			a, _ := strconv.Atoi(bs.Text())

			if a == first {
				first++
				l++
			}
		}
	}

	fmt.Println(2*n - k + 1 - 2*l)
}
