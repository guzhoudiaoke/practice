package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type tree_node struct {
	children [](*tree_node)
	value    int
}

func visit(root, parent *tree_node, m, cur int, ans *int) {
	if cur > m {
		return
	}
	if len(root.children) == 1 && root.children[0] == parent {
		*ans++
		return
	}

	for i := 0; i < len(root.children); i++ {
		if root.children[i] != parent {
			if root.children[i].value == 0 {
				visit(root.children[i], root, m, 0, ans)
			} else {
				visit(root.children[i], root, m, 1+cur, ans)
			}
		}
	}
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	nodes := make([]tree_node, n+1, n+1)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 1; i <= n; i++ {
		bs.Scan()
		nodes[i].value, _ = strconv.Atoi(bs.Text())
	}

	for i := 1; i < n; i++ {
		bs.Scan()
		p, _ := strconv.Atoi(bs.Text())
		bs.Scan()
		c, _ := strconv.Atoi(bs.Text())

		nodes[p].children = append(nodes[p].children, &nodes[c])
		nodes[c].children = append(nodes[c].children, &nodes[p])
	}

	ans := 0
	visit(&nodes[1], nil, m, nodes[1].value, &ans)
	fmt.Println(ans)
}
