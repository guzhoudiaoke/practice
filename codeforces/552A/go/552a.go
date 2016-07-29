package main

import (
	"fmt"
)

func main() {
	var n, ans int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var x1, y1, x2, y2 int
		fmt.Scan(&x1, &y1, &x2, &y2)
		ans += (x2 - x1 + 1) * (y2 - y1 + 1)
	}

	fmt.Println(ans)
}
