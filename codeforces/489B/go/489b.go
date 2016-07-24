package main

import (
    "fmt"
    "sort"
    )

func main() {
    var n, m int

    fmt.Scan(&n)
    boys := make([]int, n, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&boys[i])
    }
    sort.Sort(sort.IntSlice(boys))

    fmt.Scan(&m)
    girls := make([]int, m, m)
    for i := 0; i < m; i++ {
        fmt.Scan(&girls[i])
    }
    sort.Sort(sort.IntSlice(girls))

    i := 0
    j := 0
    result := 0
    for i < n && j < m {
        if girls[j] - boys[i] <= 1 && girls[j] - boys[i] >= -1 {
            result++
            i++
            j++
        } else if girls[j] > boys[i] {
            i++
        } else {
            j++
        }
    }

    fmt.Println(result)
}
