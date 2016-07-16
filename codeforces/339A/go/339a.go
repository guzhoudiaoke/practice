package main

import (
    "fmt"
    )

func main() {
    var line string
    fmt.Scan(&line)

    var count = [4]int{0}
    for i := 0; i < len(line); i++ {
        if line[i] != '+' {
            count[line[i] - '0']++
        }
    }

    var result string = ""
    for i := 1; i <= 3; i++ {
        for j := 0; j < count[i]; j++ {
            result += string(i + '0')
            result += "+"
        }
    }

    result = result[:len(result) - 1]
    fmt.Println(result)
}
