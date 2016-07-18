package main

import "fmt"

func main() {
    var n int64
    fmt.Scan(&n)

    var p int64 = 1
    if n % 2 == 1 {
        p = -1
    }

    fmt.Println(((n + 1) / 2) * p)
}
