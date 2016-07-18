package main

import "fmt"

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
    var a, b, c int
    fmt.Scan(&a, &b, &c)
    m := a + b + c
    m = max(m, (a + b) * c)
    m = max(m, a * (b + c))
    m = max(m, a * b * c)

    fmt.Println(m)
}
