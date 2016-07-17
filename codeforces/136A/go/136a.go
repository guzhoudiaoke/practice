package main

import "fmt"

const c_max = 128

func main() {
    var n, f int
    var result[c_max] int
    fmt.Scanf("%d\n", &n)
    for i := 1; i < n; i++ {
        fmt.Scanf("%d", &f)
        result[f] = i
    }
    fmt.Scanf("%d\n", &f)
    result[f] = n

    for i := 1; i <= n; i++ {
        fmt.Printf("%d ", result[i])
    }
    fmt.Print("\n")
}
