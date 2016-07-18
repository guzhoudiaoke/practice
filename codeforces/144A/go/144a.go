package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    heights := make([]int, n, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&heights[i])
    }

    min_i := 0
    min_v := heights[0]
    max_i := 0
    max_v := heights[0]
    for i := 1; i < len(heights); i++ {
        if heights[i] <= min_v {
            min_v = heights[i]
            min_i = i
        }
        if heights[i] > max_v {
            max_v = heights[i]
            max_i = i
        }
    }

    mov := max_i + (len(heights) - 1 - min_i)
    if max_i > min_i {
        mov -= 1
    }
    fmt.Println(mov)
}
