package main

import (
    "fmt"
    )

func main() {
    var n, m int
    fmt.Scanf("%d%d", &n, &m)

    votes := make([]uint, n, n)
    for i := 0; i < m; i++ {
        v := 0
        vm := 0
        vmi := 0
        for j := 0; j < n; j++ {
            fmt.Scan(&v)
            if v > vm {
                vm = v
                vmi = j
            }
        }
        votes[vmi]++
    }

    result := 0
    for i := 1; i < n; i++ {
        if votes[i] > votes[result] {
            result = i
        }
    }

    fmt.Println(result + 1)
}
