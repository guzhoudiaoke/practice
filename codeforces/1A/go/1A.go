package main

import "fmt"

func calc(m, n, a uint64) uint64 {
        return ((m + a - 1) / a) * ((n + a - 1) / a)
}

func main() {
        var m uint64
        var n uint64
        var a uint64
        fmt.Scanf("%d %d %d", &m, &n, &a);

        var num uint64
        num = calc(m, n, a);
        fmt.Printf("%d\n", num);
}
