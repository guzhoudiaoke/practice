package main

import (
    "fmt"
    )

func main() {
    var n int
    fmt.Scan(&n)

    an := make([]int, n, n)
    ones := 0
    for i := 0; i < n; i++ {
        fmt.Scan(&an[i])
        if an[i] == 1 {
            ones++
            an[i] = -1
        } else {
            an[i] = 1
        }
    }

    dp := make([]int, n, n)
    dp[0] = an[0]
    max := dp[0]
    for i := 1; i < n; i++ {
        dp[i] = dp[i-1] + an[i]
        if dp[i] < an[i] {
            dp[i] = an[i]
        }
        if max < dp[i] {
            max = dp[i]
        }
    }

    fmt.Println(ones + max)
}
