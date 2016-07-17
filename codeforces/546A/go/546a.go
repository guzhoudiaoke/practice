package main

import "fmt"

func calc_sum(a1, an int64) int64 {
    return (a1 + an) * (an - a1 + 1) / 2
}

func main() {
    var k, n, w int64
    fmt.Scan(&k, &n, &w)

    var result int64
    sum := calc_sum(1, w) * k

    if sum < n {
        result = 0
    } else {
        result = sum - n
    }

    fmt.Println(result)
}
