package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type edge struct {
	to  int
	len int
}

type vertex struct {
	edges []edge
}

func main() {
	var n, m, k int
	fmt.Scan(&n, &m, &k)

	var u, v, l int
	g := make([]vertex, n+1, n+1)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < m; i++ {
		//fmt.Scan(&u, &v, &l)
		bs.Scan()
		u, _ = strconv.Atoi(bs.Text())
		bs.Scan()
		v, _ = strconv.Atoi(bs.Text())
		bs.Scan()
		l, _ = strconv.Atoi(bs.Text())

		eu := edge{v, l}
		g[u].edges = append(g[u].edges, eu)
		ev := edge{u, l}
		g[v].edges = append(g[v].edges, ev)
	}

	an := make([]int, n+1, n+1)
	for i := 0; i < k; i++ {
		//fmt.Scan(&ax)
		bs.Scan()
		ax, _ := strconv.Atoi(bs.Text())
		an[ax] = 1
	}

	ans := -1
	for i := 1; i <= n; i++ {
		if an[i] == 0 {
			continue
		}
		for j := 0; j < len(g[i].edges); j++ {
			v = g[i].edges[j].to
			l = g[i].edges[j].len
			if an[v] == 0 && (ans == -1 || ans > l) {
				ans = l
			}
		}
	}

	fmt.Println(ans)
}
