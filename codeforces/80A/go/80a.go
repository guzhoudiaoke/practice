package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	is_prime := make([]int, 51, 51)
	for i := 0; i < 51; i++ {
		is_prime[i] = 1
	}
	is_prime[1] = 0
	for i := 2; i <= 8; i++ {
		if is_prime[i] == 1 {
			for x := i + i; x < 51; x += i {
				is_prime[x] = 0
			}
		}
	}

	ans := false
	for i := n + 1; i < 51; i++ {
		if is_prime[i] == 1 {
			if i == m {
				ans = true
			}
			break
		}
	}

	if ans == true {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
