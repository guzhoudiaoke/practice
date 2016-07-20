package main

import (
    "fmt"
    )

func main() {
    var n, x, i uint
    fmt.Scan(&n, &x)

    result := 0
    for i = 1; i <= n; i++ {
        if x % i == 0 && x / i <= n {
            result++
        }
    }

    fmt.Println(result)
}
