package main

import (
    "fmt"
    )

func main() {
    var n int
    fmt.Scan(&n)

    lines := make([]string, n, n)
    for i := 0; i < n; i++ {
        fmt.Scan(&lines[i])
    }

    moves := [...][2]int {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}

    ans := true
    for i := 0; i < n; i++ {
        for j := 0; j < n; j++ {
            count := 0
            for k := 0; k < 4; k++ {
                x, y := i + moves[k][0], j + moves[k][1]
                if x >= 0 && x < n && y >= 0 && y < n {
                    if lines[x][y] == 'o' {
                        count++
                    }
                }
            }

            if count % 2 != 0 {
                ans = false
                break
            }
        }

        if ans == false {
            break
        }
    }

    if ans == true {
        fmt.Println("YES")
    } else {
        fmt.Println("NO")
    }
}
