package main

import "fmt"

func main() {
    var n int
    fmt.Scanf("%d\n", &n)

    num := 0
    for i := 0; i < n; i++ {
        var p, q int
        fmt.Scan(&p, &q)
        if q - p >= 2 {
            num++
        }
    }

    fmt.Println(num)
}
