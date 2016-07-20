package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

func main() {
    var s, n int
    fmt.Scanf("%d%d\n", &s, &n)

    xi := make([]int, n, n)
    yi := make([]int, n, n)
    ki := make([]bool, n, n)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    for i := 0; i < n; i++ {
        bs.Scan()
        xi[i], _ = strconv.Atoi(bs.Text())

        bs.Scan()
        yi[i], _ = strconv.Atoi(bs.Text())

        ki[i] = false
    }

    remain := n
    for i := 0; i < n; i++ {
        kill := 0
        for j := 0; j < n; j++ {
            if ki[j] == false && xi[j] < s {
                ki[j] = true
                kill += 1
                s += yi[j]
            }
        }

        if kill == 0 {
            break
        }
        remain -= kill
    }

    if remain == 0 {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}

