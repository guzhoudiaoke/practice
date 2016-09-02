package main

import (
	"bytes"
	"fmt"
	"strconv"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var buffer bytes.Buffer
	for i := 0; i < k; i++ {
		buffer.WriteString(strconv.Itoa(n-i) + " ")
	}
	for i := 0; i < n-k; i++ {
		buffer.WriteString(strconv.Itoa(i+1) + " ")
	}

	fmt.Println(buffer.String())
}
