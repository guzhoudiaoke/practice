package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

func main() {
    var n, t int
    fmt.Scan(&n, &t)

    ports := make([]int, n, n)
    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    for i := 0; i < n-1; i++ {
        bs.Scan()
        ports[i], _ = strconv.Atoi(bs.Text())
    }

    cur := 1
    for cur < t {
        cur += ports[cur-1]
    }

    if cur == t {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
