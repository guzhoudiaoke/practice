package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
    )

func main() {
    var n int
    fmt.Scan(&n)

    minutes := make([]int, 24*60, 24*60)
    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    for i := 0; i < n; i++ {
        bs.Scan()
        h, _ := strconv.Atoi(bs.Text())
        bs.Scan()
        m, _ := strconv.Atoi(bs.Text())
        minutes[h*60 + m]++
    }

    max := 0
    for i := 0; i < 24 * 60; i++ {
        if max < minutes[i] {
            max = minutes[i]
        }
    }

    fmt.Println(max)
}
