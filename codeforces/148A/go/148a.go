package main

import "fmt"

func main() {
    var k, l, m, n, d int
    fmt.Scan(&k)
    fmt.Scan(&l)
    fmt.Scan(&m)
    fmt.Scan(&n)
    fmt.Scan(&d)

    num := 0
    for i := 1; i <= d; i++ {
        if i % k != 0 && i % l != 0 && i % m != 0 && i % n != 0 {
            num++
        }
    }

    fmt.Println(d-num)
}
