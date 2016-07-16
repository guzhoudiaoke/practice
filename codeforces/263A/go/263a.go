package main

import "fmt"

func calc_abs(n int) int {
    if n >= 0 {
        return n
    }
    return -n
}

func main() {
    const c_size int = 5
    var cell[c_size][c_size] int

    row := 0
    col := 0
    for i := 0; i < c_size; i++ {
        for j := 0; j < c_size; j++ {
            if j == c_size - 1 {
                fmt.Scanf("%d\n", &cell[i][j])
            } else {
                fmt.Scanf("%d", &cell[i][j])
            }
            if cell[i][j] == 1 {
                row = i
                col = j
            }
        }
    }

    mid := c_size / 2;
    fmt.Println(calc_abs(row - mid) + calc_abs(col - mid))
}
