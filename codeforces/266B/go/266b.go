package main

import (
    "fmt"
    )

func main() {
    var n, t int
    fmt.Scan(&n, &t)

    var q string
    fmt.Scan(&q)

    b := []byte(q)

    for i := 0; i < t; i++ {
        id := 0
        for id + 1 < n {
            if b[id] == 'B' && b[id+1] == 'G' {
                b[id], b[id+1] = b[id+1], b[id]
                id += 2
            } else {
                id += 1
            }
        }

        q = string(b)
    }

    fmt.Println(q)
}
