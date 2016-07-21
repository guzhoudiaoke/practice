package main

import (
    "fmt"
    )

func main() {
    var length[6] int
    var counts[10] int
    for i := 0; i < 6; i++ {
        fmt.Scan(&length[i])
        counts[length[i]]++
    }

    leg := -1
    for i := 0; i < 10; i++ {
        if counts[i] >= 4 {
            leg = i
        }
    }
    if leg == -1 {
        fmt.Println("Alien")
    } else {
        counts[leg] -= 4

        find := false
        for i := 0; i < 10; i++ {
            if counts[i] >= 2 {
                find = true
                break
            }
        }

        if find {
            fmt.Println("Elephant")
        } else {
            fmt.Println("Bear")
        }
    }
}
