package main

import (
    "fmt"
    )

func get_weight(piece byte) int {
    reverse := false
    if piece >= 'a' && piece <= 'z' {
        reverse = true
        piece = piece - 'a' + 'A'
    }

    ret := 0
    switch piece {
        case 'Q':
            ret = 9
        case 'R':
            ret = 5
        case 'B':
            ret = 3
        case 'N':
            ret = 3
        case 'P':
            ret = 1
    }

    if reverse {
        return -ret
    }
    return ret
}

func main() {
    var line string
    score := 0
    for i := 0; i < 8; i++ {
        fmt.Scan(&line)
        for j := 0; j < len(line); j++ {
            if (line[j] >= 'a' && line[j] <= 'z') || (line[j] >= 'A' && line[j] <= 'Z') {
                score += get_weight(line[j])
            }
        }
    }

    if score == 0 {
        fmt.Println("Draw")
    } else if score > 0 {
        fmt.Println("White")
    } else {
        fmt.Println("Black")
    }
}
