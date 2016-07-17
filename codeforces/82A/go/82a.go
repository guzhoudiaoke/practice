package main

import "fmt"


const c_num = 5
var c_names = []string{"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"}

func main() {
    var n int
    fmt.Scan(&n)

    cur := c_num
    x := 1

    n -= 1
    for n >= cur {
        n -= cur
        x *= 2
        cur = c_num * x
    }

    fmt.Println(c_names[n / x])
}
