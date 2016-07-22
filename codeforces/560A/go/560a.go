package main

import (
    "fmt"
    )

func main() {
    var n, i uint
    fmt.Scan(&n)

    find := false
    for i = 0; i < n; i++ {
        var a uint
        fmt.Scan(&a)
        if a == 1 {
            find = true
        }
    }

    if find {
        fmt.Println("-1")
    } else {
        fmt.Println("1")
    }
}
