package main

import "fmt"

func main() {
    var found[26] bool
    var name string
    fmt.Scan(&name)

    num := 0
    for i := 0; i < len(name); i++ {
        if !found[name[i] - 'a'] {
            found[name[i] - 'a'] = true
            num++
        }
    }

    if num % 2 == 0 {
        fmt.Println("CHAT WITH HER!")
    } else {
        fmt.Println("IGNORE HIM!")
    }
}
