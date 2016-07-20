package main

import "fmt"

func main() {
    var n, t int
    fmt.Scan(&n, &t)

    if t == 10 {
        if n == 1 {
            fmt.Println("-1")
        } else {
            for i := 1; i < n; i++ {
                fmt.Print("1")
            }
            fmt.Print("0\n")
        }
    } else {
        for i := 0; i < n; i++ {
            fmt.Print(t)
        }
        fmt.Print("\n")
    }
}
