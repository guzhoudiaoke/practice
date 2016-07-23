package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

func main() {
    var n, m int
    fmt.Scan(&n)

    indexn := make([]int, 1e6+1, 1e6+1)
    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    id := 1
    for i := 0; i < n; i++ {
        bs.Scan()
        a, _ := strconv.Atoi(bs.Text())
        for j := 0; j < a; j++ {
            indexn[id] = i+1
            id++
        }
    }

    bs.Scan()
    m, _ = strconv.Atoi(bs.Text())
    for i := 0; i < m; i++ {
        bs.Scan()
        p, _ := strconv.Atoi(bs.Text())
        fmt.Println(indexn[p])
    }
}
