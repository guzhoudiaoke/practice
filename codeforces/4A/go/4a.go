package main

import "fmt"

func main() {
        var w uint8
        fmt.Scanf("%d", &w);

        var re string
        if (w == 2) || (w % 2 == 1) {
                re = "NO"
        } else {
                re = "YES"
        }

        fmt.Printf(re)
}
