package main

import (
    "fmt"
    "bufio"
    "os"
    )

func main() {
    reader := bufio.NewReader(os.Stdin)
    line, _ := reader.ReadString('\n')

    chars := make([]int, 26, 26)
    for i := 0; i < len(line); i++ {
        if line[i] >= 'a' && line[i] <= 'z' {
            chars[line[i] - 'a'] += 1
        }
    }

    result := 0
    for i := 0; i < 26; i++ {
        if chars[i] != 0 {
            result += 1
        }
    }

    fmt.Println(result)
}
