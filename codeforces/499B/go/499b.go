package main

import (
    "fmt"
    )

func main() {
    var n, m int
    fmt.Scanf("%d%d\n", &n, &m)

    mm := make(map[string]string)
    for i := 0; i < m; i++ {
        var org, dst string
        fmt.Scan(&org)
        fmt.Scan(&dst)
        mm[org] = dst
    }

    result := ""
    for i := 0; i < n; i++ {
        var str string
        fmt.Scan(&str)
        if len(mm[str]) < len(str) {
            result += mm[str]
        } else {
            result += str
        }
        if i != n-1 {
            result += " "
        }
    }

    fmt.Println(result)
}
