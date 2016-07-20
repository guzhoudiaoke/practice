package main

import "fmt"

func main() {
    var colors[4] uint
    for i := 0; i < 4; i++ {
        fmt.Scan(&colors[i])
    }

    dif := 0;
    for i := 0; i < 4; i++ {
        same := false;
        for j := i+1; j < 4; j++ {
            if colors[i] == colors[j] {
                same = true;
            }
        }
        if !same {
            dif += 1
        }
    }

    fmt.Println(4 - dif)
}
