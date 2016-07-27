package main

import (
    "fmt"
    )

func main() {
    n0_9 := []string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
    n11_19 := []string{"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"}
    n10_90 := []string{"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"}

    var s int
    fmt.Scan(&s)

    if s >= 0 && s <= 9 {
        fmt.Println(n0_9[s])
    } else if s % 10 == 0 {
        fmt.Println(n10_90[s/10 - 1])
    } else if s >= 11 && s <= 19 {
        fmt.Println(n11_19[s - 11])
    } else {
        str := n10_90[s/10-1]
        str += "-"
        str += n0_9[s%10]
        fmt.Println(str)
    }
}
