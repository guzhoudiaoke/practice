package main

import (
    "fmt"
    )

func get_line(index, n int) string {
    line := make([]byte, n, n)
    if index > n / 2 {
        index = n - index - 1
    }

    nd := index * 2 + 1
    nstar := (n - nd) / 2
    i := 0
    for ; i < nstar; i++ {
        line[i] = '*'
        line[n-i-1] = '*'
    }
    for ; i < nstar + nd; i++ {
        line[i] = 'D'
    }

    return string(line)
}

func main() {
    var n int
    fmt.Scan(&n)

    for i := 0; i < n; i++ {
        line := get_line(i, n)
        fmt.Println(line)
    }
}
