package main

import "fmt"

func main() {
        var n uint32
        var length int
        var str string
        fmt.Scanf("%d", &n)

        for n != 0 {
                fmt.Scanf("%s", &str)
                length = len(str)
                if (length < 10) {
                        fmt.Println(str)
                } else {
                        fmt.Printf("%c%d%c\n", str[0], length - 2, str[length-1])
                }
                n--
        }
}
