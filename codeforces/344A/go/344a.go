package main

import (
    "fmt"
    "bufio"
    "os"
    )

func main() {
    var n int
    fmt.Scanf("%d\n", &n)

    magnets := make([]string, n, n)
    bs := bufio.NewScanner(os.Stdin)
    for i := 0; i < n; i++ {
        bs.Scan()
        magnets[i] = bs.Text()
    }

    /*reader := bufio.NewReader(os.Stdin)
    for i := 0; i < n; i++ {
        bytes, _, _ := reader.ReadLine()
        magnets[i] = string(bytes)
    }*/

    group := 1
    pre := magnets[0]
    for i := 1; i < n; i++ {
        if pre != magnets[i] {
            pre = magnets[i]
            group += 1
        }
    }

    fmt.Println(group)
}
