package main

import "fmt"

func is_lucky(n int) bool {
    for n != 0 {
        mod := n % 10
        n /= 10
        if mod != 4 && mod != 7 {
            return false
        }
    }
    return true
}

func almost_lucky(n int) bool {
    for i := 4; i <= n; i++ {
        if is_lucky(i) && n % i == 0 {
            return true
        }
    }
    return false
}

func main() {
    var n int
    fmt.Scanf("%d", &n)
    if (almost_lucky(n)) {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
