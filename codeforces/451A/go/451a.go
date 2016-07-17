package main

import "fmt"

func play(n, m int) int {
    if m == 1 || n == 1 {
        return 1
    }
    return play(n-1, m-1) ^ 1
}

func main() {
    var n, m int
    fmt.Scan(&n, &m)

    if (play(n, m) & 0x1) == 0 {
        fmt.Println("Malvika")
    } else {
        fmt.Println("Akshat")
    }
}
