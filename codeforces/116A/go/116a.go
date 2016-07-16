package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    var m, cur int
    m = 0
    cur = 0
    for i := 0; i < n; i++ {
        var leave, enter int
        fmt.Scan(&leave, &enter)
        cur -= leave
        cur += enter
        if m < cur {
            m = cur
        }
    }

    fmt.Println(m)
}
