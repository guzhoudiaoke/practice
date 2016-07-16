package main

import "fmt"

func max(a int, b int) int {
    if a > b {
        return a
    }
    return b
}

func main() {
    var n int = 0
    var groups = [5]int{0, 0, 0, 0, 0}

    fmt.Scanf("%d\n", &n)
    for i := 0; i < n; i++ {
        var g int
        fmt.Scanf("%d", &g)
        groups[g]++
    }

    result := groups[4] + groups[3]
    groups[1] = max(0, groups[1] - groups[3])
    result += (groups[2] + 1) / 2
    groups[1] = max(0, groups[1] - groups[2] % 2 * 2)
    result += (groups[1] + 3) / 4

    fmt.Println(result)
}
