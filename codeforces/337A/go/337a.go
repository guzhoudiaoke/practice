package main

import (
    "fmt"
    "sort"
    )

func main() {
    var n, m int
    var f[50] int

    fmt.Scanf("%d%d\n", &n, &m)
    for i := 0; i < m; i++ {
        //if i != m-1 {
        fmt.Scanf("%d", &f[i])
        //} else {
            //fmt.Scanf("%d\n", &f[i])
        //}
    }

    sort.Ints(f[:m])
    result := 1000
    for i := 0; i <= m-n; i++ {
        if result > f[i+n-1] - f[i] {
            result = f[i+n-1] - f[i]
        }
    }

    fmt.Println(result)
}
