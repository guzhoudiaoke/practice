package main

import "fmt"

func main() {
    var s string
    fmt.Scan(&s)

    var dst string = "hello"
    id := 0
    total := len(dst)
    for i := 0; i < len(s) && id < total; i++ {
        if s[i] == dst[id] {
            id++
        }
    }

    if id == total {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
