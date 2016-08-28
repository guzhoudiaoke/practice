package main

import "fmt"

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func main() {
	var n int
	fmt.Scanf("%d\n", &n)

	var gender byte
	var s, e int
	count_m := make([]int, 367, 367)
	count_f := make([]int, 367, 367)

	for i := 0; i < n; i++ {
		fmt.Scanf("%c %d %d\n", &gender, &s, &e)
		if gender == 'M' {
			for j := s; j <= e; j++ {
				count_m[j]++
			}
		} else {
			for j := s; j <= e; j++ {
				count_f[j]++
			}
		}
	}

	ans := 0
	for i := 1; i < 367; i++ {
		m := min(count_m[i], count_f[i])
		if m+m > ans {
			ans = m + m
		}
	}

	fmt.Println(ans)
}
