package main

import (
    "fmt"
    "strings"
)

func main() {
    var a string
    var b string

    fmt.Scan(&a)
    a = strings.ToLower(a)
    fmt.Scan(&b)
    b = strings.ToLower(b)

    if a == b {
        fmt.Println("0")
    } else if (a < b) {
        fmt.Println("-1")
    } else {
        fmt.Println("1")
    }
}
