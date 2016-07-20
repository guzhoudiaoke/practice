package main

import (
    "fmt"
    )

const keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./"

func get_real(mov string, ch byte) string {
    i := 0
    for i = 0; i < len(keyboard); i++ {
        if keyboard[i] == ch {
            break
        }
    }
    if mov == "R" {
        return string(keyboard[i-1])
    } else {
        return string(keyboard[i+1])
    }
}

func main() {
    var mov string
    fmt.Scan(&mov)

    var line string
    fmt.Scan(&line)

    result := ""
    for i := 0; i < len(line); i++ {
        result += get_real(mov, line[i])
    }

    fmt.Println(result)
}
