package main

import (
    "fmt"
    )

func main() {
    var n, m int
    fmt.Scan(&n, &m)

    min := (n+1) / 2
    max := n
    ret := -1
    for i := min; i <= max; i++ {
        if i % m == 0 {
            ret = i
            break
        }
    }
    fmt.Println(ret)
}
