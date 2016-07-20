package main

import "fmt"

func main() {
    cups := 0
    medals := 0

    var a1, a2, a3, b1, b2, b3 int
    fmt.Scanf("%d%d%d\n", &a1, &a2, &a3)
    fmt.Scanf("%d%d%d\n", &b1, &b2, &b3)

    cups = a1 + a2 + a3
    medals = b1 + b2 + b3

    var n int
    fmt.Scanf("%d", &n)

    num := (cups + 4) / 5 + (medals + 9) / 10
    if num <= n {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
