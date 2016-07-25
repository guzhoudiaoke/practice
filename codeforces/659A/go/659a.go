package main

import (
    "fmt"
    )

func main() {
    var n, a, b int
    fmt.Scan(&n, &a, &b)
    fmt.Println(((a + b - 1) % n + n) % n + 1)
}
