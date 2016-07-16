package main

import "fmt"

func main() {
    var n int
    fmt.Scanf("%d\n", &n)

    var coin, sum int
    sum = 0
    var count = [101]int{0:101}
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &coin)
        sum += coin
        count[coin]++
    }

    cur := 0
    num := 0
    find := false
    for i := 100; i >= 0 && !find; i-- {
        for j := 0; j < count[i]; j++ {
            cur += i
            num++
            if (cur > sum - cur) {
                find = true
                break
            }
        }
    }

    fmt.Println(num)
}
