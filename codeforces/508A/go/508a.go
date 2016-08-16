package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func is_lose(img [][]int, x, y int) bool {
	ret := false
	if img[x-1][y-1]+img[x-1][y]+img[x][y-1]+img[x][y] == 4 {
		ret = true
	} else if img[x-1][y+1]+img[x-1][y]+img[x][y+1]+img[x][y] == 4 {
		ret = true
	} else if img[x+1][y-1]+img[x+1][y]+img[x][y-1]+img[x][y] == 4 {
		ret = true
	} else if img[x+1][y+1]+img[x+1][y]+img[x][y+1]+img[x][y] == 4 {
		ret = true
	}

	return ret
}

/*
func dump(img [][]int, n, m int) {
	for i := 0; i < n+2; i++ {
		for j := 0; j < m+2; j++ {
			fmt.Printf("%d ", img[i][j])
		}
		fmt.Println()
	}
}
*/

func main() {
	var n, m, k int
	fmt.Scan(&n, &m, &k)

	img := [][]int{}
	for i := 0; i <= n+1; i++ {
		row := make([]int, m+2, m+2)
		img = append(img, row)
	}

	ans := 0
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)
	for i := 0; i < k; i++ {
		bs.Scan()
		x, _ := strconv.Atoi(bs.Text())
		bs.Scan()
		y, _ := strconv.Atoi(bs.Text())

		img[x][y] = 1
		//dump(img, n, m)
		if is_lose(img, x, y) {
			ans = i + 1
			break
		}
	}

	fmt.Println(ans)
}
