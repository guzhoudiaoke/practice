package main

import (
    "fmt"
    )

func calc(m, s int) (string, string) {
    if m == 1 && s == 0 {
        return "0", "0"
    } else if s < 1 || m * 9 < s {
        return "-1", "-1"
    }

    min := make([]byte, m, m)
    cur := s - 1
    min [0] = '1'
    if s - 9*(m-1) > 1 {
        min[0] = byte(s - 9*(m-1) + '0')
        cur = 9 * (m-1)
    }

    for i := m-1; i >= 1; i-- {
        if cur > 9 {
            min[i] = '9'
            cur -= 9
        } else {
            min[i] = byte('0' + cur)
            cur = 0
        }
    }

    max := make([]byte, m, m)
    cur = s
    for i := 0; i < m; i++ {
        if cur > 9 {
            max[i] = '9'
            cur -= 9
        } else {
            max[i] = byte('0' + cur)
            cur = 0
        }
    }

    return string(min), string(max)
}

func main() {
    var m, s int
    fmt.Scan(&m, &s)

    min, max := calc(m, s)
    fmt.Println(min, max)
}
