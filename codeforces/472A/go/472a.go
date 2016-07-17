package main

import (
    "fmt"
    "math"
    )

func main() {
    var n int
    fmt.Scan(&n)

    is_prime := make([]bool, n+1)
    for i := 0; i <= n; i++ {
        is_prime[i] = true;
    }
    for i := 2; i <= int(math.Sqrt(float64(n))); i++ {
        for j := 2; i*j <= n; j++ {
            if is_prime[i] {
                is_prime[i*j] = false
            }
        }
    }

    x := n/2
    for x >= 4 {
        if !is_prime[x] && !is_prime[n-x] {
            break
        }
        x--
    }

    fmt.Printf("%d %d\n", x, n-x)
}
