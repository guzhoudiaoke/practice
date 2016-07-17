package main

import (
    "fmt"
    )

func correct(s, t string) bool {
    lens := len(s)
    lent := len(t)
    if lens != lent {
        return false
    }

    for i := 0; i < lens; i++ {
        if s[i] != t[lens-i-1] {
            return false
        }
    }

    return true
}

func main() {
    var s, t string
    fmt.Scan(&s)
    fmt.Scan(&t)

    if correct(s, t) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
