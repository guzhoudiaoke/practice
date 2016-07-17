package main

import "fmt"

func is_beautiful(y int) bool {
    var have[10] bool
    for i := 0; i < 10; i++ {
        have[i] = false
    }
    for y != 0 {
        mod := y % 10
        if have[mod] {
            return false
        } else {
            have[mod] = true
        }
        y /= 10
    }

    return true
}

func main() {
    var year int
    fmt.Scan(&year)

    i := 0
    for i = year+1; i < 10000; i++ {
        if is_beautiful(i) {
            break
        }
    }

    fmt.Println(i)
}
