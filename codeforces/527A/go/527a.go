package main

import (
    "fmt"
    )

func calc(a, b uint64) uint64 {
    if a == 0 || b == 0 {
        return 0
    }

    if a < b {
        tmp := a
        a = b
        b = tmp
    }

    return a/b + calc(a%b, b)
}

func main() {
    var a, b uint64
    fmt.Scan(&a, &b)
    fmt.Println(calc(a, b))
}
