package main

import "fmt"

func main() {
    var a, b int

    wentout := 0
    hour := 0

    fmt.Scan(&a, &b)
    for a > 0 {
        hour += a
        wentout += a
        if wentout >= b {
            a = wentout / b
            wentout -= a*b
        } else {
            break
        }
    }

    fmt.Println(hour)
}
