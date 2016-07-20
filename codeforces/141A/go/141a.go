package main

import "fmt"

func main() {
    var line1, line2, line3 string
    fmt.Scan(&line1)
    fmt.Scan(&line2)
    fmt.Scan(&line3)

    var total1[26] int
    var total2[26] int

    for i := 0; i < len(line1); i++ {
        total1[line1[i] - 'A'] += 1
    }
    for i := 0; i < len(line2); i++ {
        total1[line2[i] - 'A'] += 1
    }

    for i := 0; i < len(line3); i++ {
        total2[line3[i] - 'A'] += 1
    }

    ret := true
    for i := 0; i < 26; i++ {
        if total1[i] != total2[i] {
            ret = false
            break
        }
    }

    if ret {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
