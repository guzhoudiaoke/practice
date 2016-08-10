package main

import (
	"fmt"
	"strconv"
)

func pow(a, p int) int {
	ans := 1
	for i := 0; i < p; i++ {
		ans *= a
	}
	return ans
}

func main() {
	var line string
	fmt.Scan(&line)

	length := len(line)
	num := 0
	if length >= 2 {
		num, _ = strconv.Atoi(line[length-2 : length])
	} else {
		num, _ = strconv.Atoi(string(line[length-1]))
	}

	num = (num-1)%4 + 1
	ans := (pow(1, num) + pow(2, num) + pow(3, num) + pow(4, num)) % 5
	fmt.Println(ans)
}
