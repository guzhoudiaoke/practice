package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	an := make([]int, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&an[i])
	}

	ans := make([]int, n*2, n*2)
	index := 0

	for i := 0; i < n; i++ {
		t := i
		for j := i + 1; j < n; j++ {
			if an[t] > an[j] {
				t = j
			}
		}

		if t != i {
			an[i], an[t] = an[t], an[i]
			ans[index] = i
			index++
			ans[index] = t
			index++
		}
	}

	cnt := index / 2
	fmt.Println(cnt)
	for i := 0; i < cnt; i++ {
		fmt.Println(ans[i*2], ans[i*2+1])
	}
}
