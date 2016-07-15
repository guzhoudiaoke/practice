package main

import "fmt"

func main() {
    var n int
    var a, b, c int
    var result int = 0

    fmt.Scan(&n)
    for i := 0; i < n; i++ {
        fmt.Scan(&a, &b, &c)
        if a + b + c >= 2 {
            result++
        }
    }
    fmt.Println(result)
}
