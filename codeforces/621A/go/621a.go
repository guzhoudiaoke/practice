package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

func main() {
    var n, i int
    var sum, a, minodd int64
    fmt.Scan(&n)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    minodd = 1e9
    for i = 0; i < n; i++ {
        bs.Scan()
        a, _ = strconv.ParseInt(bs.Text(), 10, 64)
        if a % 2 == 0 {
            sum += a
        } else {
            if minodd > a {
                if minodd != 1e9 {
                    sum += minodd
                }
                minodd = a
            } else {
                sum += a
            }
        }
    }

    if sum % 2 != 0 {
        sum += minodd
    }

    fmt.Println(sum)
}
