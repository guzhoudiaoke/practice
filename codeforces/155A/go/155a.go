package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

func main() {
    var n int
    fmt.Scan(&n)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)

    bs.Scan()
    num, _ := strconv.Atoi(bs.Text())

    min := num
    max := num
    result := 0
    for i := 1; i < n; i++ {
        bs.Scan()
        num, _ = strconv.Atoi(bs.Text())
        if min > num {
            min = num
            result++
        }
        if max < num {
            max = num
            result++
        }
    }

    fmt.Println(result)
}
