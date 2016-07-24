package main

import (
    "fmt"
    )

func main() {
    var n, v int
    fmt.Scan(&n, &v)

    sellers := make([]bool, n, n)
    count := 0
    for i := 0; i < n; i++ {
        var k, s int
        min := 1000001
        fmt.Scan(&k)
        for j := 0; j < k; j++ {
            fmt.Scan(&s)
            if s < min {
                min = s
            }
        }
        if min < v {
            count++
            sellers[i] = true
        }
    }

    fmt.Println(count)
    if count > 0 {
        for i := 0; i < n; i++ {
            if sellers[i] {
                fmt.Print(i+1, " ")
            }
        }
        fmt.Println("")
    }
}
