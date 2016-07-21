package main

import (
    "fmt"
    )

func main() {
    var n, d int
    fmt.Scan(&n, &d)

    sum := 0
    for i := 0; i < n; i++ {
        var t int
        fmt.Scan(&t)
        sum += t
    }

    total := 10 * (n-1) + sum
    result := -1
    if total <= d {
        result = (d-total) / 5 + 2 * (n-1)
    }

    fmt.Println(result)
}
