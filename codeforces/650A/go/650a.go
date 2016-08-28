package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type point struct {
	x int
	y int
}

func main() {
	var n int
	fmt.Scan(&n)

	mx := make(map[int]int)
	my := make(map[int]int)
	mp := make(map[point]int)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < n; i++ {
		bs.Scan()
		x, _ := strconv.Atoi(bs.Text())

		bs.Scan()
		y, _ := strconv.Atoi(bs.Text())

		pt := point{x, y}

		mx[x]++
		my[y]++
		mp[pt]++
	}

	var ans uint64
	ans = 0
	for _, v := range mx {
		if v > 1 {
			ans += uint64(v) * uint64(v-1) / 2
		}
	}
	for _, v := range my {
		if v > 1 {
			ans += uint64(v) * uint64(v-1) / 2
		}
	}

	for _, v := range mp {
		if v > 1 {
			ans -= uint64(v) * uint64(v-1) / 2
		}
	}

	fmt.Println(ans)
}
