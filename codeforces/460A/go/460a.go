package main

import "fmt"

func main() {
    var m, n int
    fmt.Scan(&n, &m)

    day := 0
    mom := 0
    for n > 0 {
        day += n
        mom += n
        if mom >= m {
            n = mom / m
            mom -= m*n
        } else {
            break
        }
    }

    fmt.Println(day)
}
