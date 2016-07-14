package main

import (
	"fmt"
)

const LONG_WORD_LEN int = 10

func main() {
        var n uint32
        fmt.Scanf("%d", &n)

        for n != 0 {
		var str string
		fmt.Scan(&str)

		length := len(str)
                if (length <= LONG_WORD_LEN) {
                        fmt.Printf("%s\n", str)
                } else {
                        fmt.Printf("%c%d%c\n", str[0], length - 2, str[length-1])
                }

                n--
        }
}
