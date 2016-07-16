package main

import (
    "fmt"
    "strings"
    )

func main() {
    var players string
    fmt.Scan(&players)
    if strings.Contains(players, "0000000") || strings.Contains(players, "1111111") {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
