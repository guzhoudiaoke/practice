package main

import (
    "fmt"
    )

func main() {
    var m, n int
    fmt.Scan(&n, &m)

    bulbs := make([]bool, m, m)
    for i := 0; i < n; i++ {
        var x, y int
        fmt.Scan(&x)
        for j := 0; j < x; j++ {
            fmt.Scan(&y)
            bulbs[y-1] = true
        }
    }

    possible := true
    for i := 0; i < m; i++ {
        if bulbs[i] == false {
            possible = false
            break
        }
    }

    if possible {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
