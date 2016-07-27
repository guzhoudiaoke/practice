package main

import (
    "fmt"
    )

type child struct {
    index   int
    left    int
}

func main() {
    var n, m int
    fmt.Scan(&n, &m)

    an := make([]child, 2*n, 2*n)
    for i := 0; i < n; i++ {
        var a int
        fmt.Scan(&a)
        an[i].left = a
        an[i].index = i+1
    }

    left := n
    ans := n
    for left > 0 {
        tmp := left
        left = 0
        for i := 0; i < tmp; i++ {
            if an[i].left > m {
                an[n+left].index, an[n+left].left = an[i].index, an[i].left-m
                left++
            }
        }
        if left == 0 {
            ans = an[tmp-1].index
            break
        }
        for i := n; i < left+n; i++ {
            an[i-n].index, an[i-n].left = an[i].index, an[i].left
        }
    }

    fmt.Println(ans)
}
