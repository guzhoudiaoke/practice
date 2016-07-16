package main

import (
    "fmt"
    "strings"
    )

func main() {
    var s string
    fmt.Scan(&s)

    if strings.Contains(s, "H") || strings.Contains(s, "Q") || strings.Contains(s, "9") {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
