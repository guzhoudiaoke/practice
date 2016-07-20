package main

import "fmt"

func main() {
    var n, m, a, b int
    fmt.Scan(&n, &m, &a, &b)

    min := 0
    if m*a <= b {
        min = n * a;
    } else {
        ms := n / m
        mod := n % m
        min = ms * b;
        if mod*a <= b {
            min += mod*a
        } else {
            min += b
        }
    }

    fmt.Println(min)
}
