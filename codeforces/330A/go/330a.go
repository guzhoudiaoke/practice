package main

import (
    "fmt"
    )

func main() {
    var r, c int
    fmt.Scan(&r, &c)

    rs := 0
    cx := make([]bool, c, c)
    for i := 0; i < r; i++ {
        var line string
        fmt.Scan(&line)
        find := false
        for j := 0; j < c; j++ {
            if line[j] == 'S' {
                find = true
                cx[j] = true
            }
        }
        if find {
            rs++
        }
    }

    cs := 0
    for i := 0; i < c; i++ {
        if cx[i] {
            cs++
        }
    }

    fmt.Println(r*c - rs*cs)
}
