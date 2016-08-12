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

	in := make([]bool, 1000001, 1000001)
	cur := 0
	ans := 0

	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		c := bs.Text()[0]
		bs.Scan()
		p, _ := strconv.Atoi(bs.Text())
		if c == '+' {
			in[p] = true
			cur++
			if ans < cur {
				ans = cur
			}
		} else {
			if in[p] == true {
				cur--
			} else {
				ans++
			}
			in[p] = false
		}
	}

	fmt.Println(ans)
}
