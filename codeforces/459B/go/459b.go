package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

func main() {
    var n, min, max, i, a int64
    var minnum, maxnum, count int64
    fmt.Scan(&n)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    min = 1e9 + 1
    minnum = 0
    max = 0
    maxnum = 0
    for i = 0; i < n; i++ {
        bs.Scan()
        a, _ = strconv.ParseInt(bs.Text(), 10, 64)
        if a == min {
            minnum++
        } else if a < min {
            min = a
            minnum = 1
        }

        if a == max {
            maxnum++
        } else if a > max {
            max = a
            maxnum = 1
        }
    }

    count = maxnum*minnum
    if min == max {
        count = n * (n-1) / 2
    }
    fmt.Println(max-min, count)
}
