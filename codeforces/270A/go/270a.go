package main

import (
    "fmt"
    )

func can_build(angle int) bool {
    for i := 3; angle * i >= 180 * (i-2); i++ {
        if angle * i == 180 * (i-2) {
            return true
        }
    }

    return false
}

func main() {
    var t int
    fmt.Scan(&t)

    for i := 0; i < t; i++ {
        var angle int
        fmt.Scan(&angle)
        if can_build(angle) {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}
