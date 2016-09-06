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

	an := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)

	sum := 0
	for i := 0; i < n; i++ {
		bs.Scan()
		an[i], _ = strconv.Atoi(bs.Text())
		sum += an[i]
	}

	ans := sum
	jmp := 2
	for jmp = 2; jmp*3 <= n; jmp++ {
		if n%jmp != 0 {
			continue
		}
		for j := 0; j < jmp; j++ {
			sum = 0
			for i := j; i < n; i += jmp {
				sum += an[i]
			}
			if sum > ans {
				ans = sum
			}
		}
	}

	fmt.Println(ans)
}
