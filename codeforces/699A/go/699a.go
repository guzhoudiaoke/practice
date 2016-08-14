package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	var moves string
	fmt.Scan(&n)
	fmt.Scan(&moves)

	xn := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		xn[i], _ = strconv.Atoi(bs.Text())
	}

	pre := -1
	ans := -1
	for i := 0; i < n; i++ {
		if moves[i] == 'R' {
			pre = i
		} else {
			if pre != -1 && (ans == -1 || ans > (xn[i]-xn[pre])/2) {
				ans = (xn[i] - xn[pre]) / 2
			}
		}
	}

	fmt.Println(ans)
}
