package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)

    nums := make([]int, n, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&nums[i])
    }

    even := 0
    for i := 0; i < 3; i++ {
        if nums[i] % 2 == 0 {
            even += 1
        }
    }

    mod := 0
    if even >= 2 {
        mod = 1
    }

    var ret int
    for i := 0; i < n; i++ {
        if nums[i] % 2 == mod {
            ret = i + 1
            break
        }
    }

    fmt.Println(ret)
}
