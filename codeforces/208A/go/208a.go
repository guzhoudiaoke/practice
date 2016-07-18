package main

import "fmt"

func main() {
    var song, result string
    fmt.Scan(&song)

    i := 0
    for i < len(song) {
        if i+2 < len(song) && song[i] == 'W' && song[i+1] == 'U' && song[i+2] == 'B' {
            length := len(result)
            if length > 0 && result[length-1] != ' ' {
                result += string(' ')
            }
            i += 3
        } else {
            result += string(song[i])
            i += 1
        }
    }

    if result[len(result) - 1] == ' ' {
        result = result[:len(result) - 1]
    }
    fmt.Println(result)
}
