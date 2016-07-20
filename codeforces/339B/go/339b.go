package main

import (
    "fmt"
    "bufio"
    "strconv"
    "os"
    )

func calc_mov(n, from, to int) uint64 {
    if to >= from {
        return uint64(to - from)
    }
    return uint64(n - from + to)
}

func main() {
    var n, m int
    fmt.Scanf("%d%d\n", &n, &m)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)

    from := 1
    var mov uint64 = 0
    for i := 0; i < m; i++ {
        bs.Scan()
        to, _ := strconv.Atoi(bs.Text())
        mov += calc_mov(n, from, to)
        from = to
    }

    fmt.Println(mov)
}
