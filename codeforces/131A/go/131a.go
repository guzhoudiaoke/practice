package main

import "fmt"

func is_upper(ch byte) bool {
    return ch >= 'A' && ch <= 'Z'
}

func main() {
    var s string
    fmt.Scan(&s)

    var count int = 0
    for i := 1; i < len(s); i++ {
        if is_upper(s[i]) {
            count++
        }
    }

    var result string = ""
    if count == len(s) - 1 {
        for i := 0; i < len(s); i++ {
            if is_upper(s[i]) {
                result += string(s[i] - 'A' + 'a')
            } else {
                result += string(s[i] - 'a' + 'A')
            }
        }
    } else {
        result = s
    }

    fmt.Println(result)
}
