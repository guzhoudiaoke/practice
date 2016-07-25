package main

import (
    "fmt"
    )

func main() {
    var l, p, q int
    fmt.Scan(&l, &p, &q)

    fmt.Println(float32(l * p) / float32(p+q))
}
