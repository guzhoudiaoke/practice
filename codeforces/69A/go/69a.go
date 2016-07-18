package main

import "fmt"

func main() {
    n := 0
    x := 0
    y := 0
    z := 0

    fmt.Scan(&n)
    for i := 0; i < n; i++ {
        var a, b, c int
        fmt.Scan(&a, &b, &c)
        x += a; y += b; z += c
    }

    if x == 0 && y == 0 && z == 0 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
