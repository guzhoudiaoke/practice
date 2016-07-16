package main

import "fmt"

func main() {
    var n int = 0
    var s string

    fmt.Scan(&n)
    fmt.Scan(&s)

    var count int = 0
    for i := 1; i < n; i++ {
        if s[i] == s[i-1]{
            count++;
        }
    }

    fmt.Println(count)
}
