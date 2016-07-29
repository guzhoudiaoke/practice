package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func solve(n int, an []int) (can bool, left, right int) {
	/* find left */
	left = -1
	for i := 0; i < n-1; i++ {
		if an[i+1] < an[i] {
			left = i
			break
		}
	}

	/* sorted */
	if left == -1 {
		return true, 1, 1
	}

	/* find right */
	right = -1
	for i := left; i < n-1; i++ {
		if an[i] < an[i+1] {
			right = i
			break
		}
	}
	if right == -1 {
		right = n - 1
	}

	for i := right + 1; i < n; i++ {
		if an[i] < an[i-1] {
			return false, -1, -1
		}
	}

	if left >= 1 && an[left-1] > an[right] {
		return false, -1, -1
	}
	if right != n-1 && an[right+1] < an[left] {
		return false, -1, -1
	}

	return true, left + 1, right + 1
}

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n, n)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)

	for i := 0; i < n; i++ {
		bs.Scan()
		an[i], _ = strconv.Atoi(bs.Text())
	}

	can, left, right := solve(n, an)
	if can {
		fmt.Println("yes")
		fmt.Println(left, right)
	} else {
		fmt.Println("no")
	}
}
