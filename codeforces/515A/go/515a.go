package main

import (
    "fmt"
    )

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}

func main() {
    var a, b, s int
    fmt.Scan(&a, &b, &s)

    delta := s - (abs(a) + abs(b))
    if delta < 0 {
        fmt.Println("No")
    } else if delta & 1 == 0 {
        fmt.Println("Yes")
    } else {
        fmt.Println("No")
    }
}
