package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    "math"
    )

const c_max = 1000000

func check(x int64, is_prime []bool) string {
    if x < 4 {
        return "NO"
    }

    var sqrt int64
    sqrt = int64(math.Sqrt(float64(x)))
    if sqrt * sqrt != x {
        return "NO"
    }

    if is_prime[sqrt] {
        return "YES"
    }

    return "NO"
}

func init_prime(is_prime []bool) {
    for i := 0; i <= c_max; i++ {
        is_prime[i] = true
    }

    sq := int(math.Sqrt(float64(c_max))) + 1
    for i := 2; i <= sq; i++ {
        if is_prime[i] {
            for j := 2; j <= c_max/i; j++ {
                is_prime[i*j] = false
            }
        }
    }
}

func main() {
    var n int
    fmt.Scan(&n)

    is_prime := make([]bool, c_max+1, c_max+1)
    init_prime(is_prime)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    for i := 0; i < n; i++ {
        bs.Scan()
        x, _ := strconv.ParseInt(bs.Text(), 10, 64)
        fmt.Println(check(x, is_prime))
    }
}
