package main

import (
    "fmt"
    )

func main() {
    var n, m int
    fmt.Scan(&n, &m)

    ans := 0
    for a := 0; a <= m; a++ {
        b := n - a*a
        if b >= 0 && a + b*b == m {
            ans++
        }
    }

    fmt.Println(ans)
}
