package main

import (
    "fmt"
    )

func main() {
    var n int
    fmt.Scan(&n)

    event := 0
    police := 0
    result := 0
    for i := 0; i < n; i++ {
        fmt.Scan(&event)
        if event < 0 {
            if police > 0 {
                police--
            } else {
                result++
            }
        } else {
            police += event
        }
    }

    fmt.Println(result)
}
