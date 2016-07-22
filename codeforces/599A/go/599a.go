package main

import (
    "fmt"
    )

func min(x, y uint) uint {
    if x < y {
        return x
    }
    return y
}

func main() {
    var d1, d2, d3 uint
    fmt.Scan(&d1, &d2, &d3)

    dis1 := d1 + d2 + d3
    dis2 := 2*d1 + 2*d2
    dist := min(dis1, dis2)
    dis3 := 2*d2 + 2*d3
    dist = min(dist, dis3)
    dis4 := 2*d1 + 2*d3
    dist = min(dist, dis4)

    fmt.Println(dist)
}
