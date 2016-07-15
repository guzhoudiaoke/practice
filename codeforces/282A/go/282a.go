package main

import "fmt"

func main() {
    var n int
    var result int = 0
    var cmd string

    fmt.Scan(&n)
    for i := 0; i < n; i++ {
        fmt.Scan(&cmd)
        if cmd == "++X" || cmd == "X++" {
            result++
        } else if cmd == "--X" || cmd == "X--" {
            result--
        }
    }
    fmt.Println(result)
}
