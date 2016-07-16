package main

import "fmt"

func main() {
    var s string
    fmt.Scan(&s)
    if s[0] >= 'a' && s[0] <= 'z' {
        s = string(s[0] - 'a' + 'A') + s[1:]
    }

    fmt.Println(s)
}
