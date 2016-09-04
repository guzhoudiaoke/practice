package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type name struct {
	first string
	last  string
}

func min(a, b string) string {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n int
	fmt.Scan(&n)

	names := make([]name, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		names[i].first = bs.Text()
		bs.Scan()
		names[i].last = bs.Text()
	}

	pn := make([]int, n, n)
	for i := 0; i < n; i++ {
		bs.Scan()
		pn[i], _ = strconv.Atoi(bs.Text())
	}

	ans := true
	handle := ""
	for i := 0; i < n; i++ {
		index := pn[i] - 1
		if i == 0 {
			handle = min(names[index].first, names[index].last)
		} else {
			if handle < names[index].first && handle < names[index].last {
				handle = min(names[index].first, names[index].last)
			} else if handle < names[index].first {
				handle = names[index].first
			} else if handle < names[index].last {
				handle = names[index].last
			} else {
				ans = false
				break
			}
		}
	}

	if ans {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
