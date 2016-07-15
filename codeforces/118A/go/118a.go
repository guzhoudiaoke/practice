package main

import (
    "fmt"
    "strings"
    )

func main() {
    var word string
    var result string
    var vowel[26] bool
    for i := 0; i < 26; i++ {
        vowel[i] = false
    }
    vowel['a'-'a'] = true
    vowel['e'-'a'] = true
    vowel['i'-'a'] = true
    vowel['o'-'a'] = true
    vowel['u'-'a'] = true
    vowel['y'-'a'] = true

    fmt.Scan(&word)
    word = strings.ToLower(word)
    for i := 0; i < len(word); i++ {
        if (!vowel[word[i] - 'a']) {
            result += string('.')
            result += string(word[i])
        }
    }

    fmt.Println(result)
}
