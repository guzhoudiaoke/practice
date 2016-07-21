package main

import (
    "fmt"
    )

func main() {
    var n, k, yn int
    fmt.Scanf("%d%d\n", &n, &k)

    count := 0
    for i := 0; i < n; i++ {
        fmt.Scan(&yn)
        if yn + k <= 5 {
            count++
        }
    }

    fmt.Println(count / 3)
}
