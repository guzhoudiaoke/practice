package main

import "fmt"


func is_lucky(n int) bool {
    if n == 0 {
        return false
    }

    for n != 0 {
        mod := n % 10
        n /= 10
        if mod != 4 && mod != 7 {
            return false
        }
    }

    return true
}

func main() {
    var num string
    fmt.Scan(&num)

    n := 0
    for i := 0; i < len(num); i++ {
        if num[i] == '4' || num[i] == '7' {
            n++
        }
    }

    if (is_lucky(n)) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
