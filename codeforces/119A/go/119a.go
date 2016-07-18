package main

import "fmt"

func gcd(a, b int) int {
        if b == 0 {
                return a
        }
        return gcd(b, a % b)
}

func main() {
        var a, b, n int
        fmt.Scan(&a, &b, &n)

        result := true
        rm := 0
        for n > 0 {
                if result == true {
                        rm = gcd(a, n)
                } else {
                        rm = gcd(b, n)
                }
                if n < rm {
                        break
                }
                n -= rm
                result = !result
        }

        if result {
                fmt.Println("1")
        } else {
                fmt.Println("0")
        }
}
