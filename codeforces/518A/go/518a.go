package main

import "fmt"

func main() {
	var s, t, ans string
	fmt.Scan(&s, &t)

	suff := 0
	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			suff = i
			break
		}
	}

	ans = s[0:suff]
	tmp := ""
	carry := true
	for i := len(s) - 1; i >= suff; i-- {
		if carry {
			if s[i] == 'z' {
				tmp = "a" + tmp
				carry = true
			} else {
				tmp = string(s[i]+1) + tmp
				carry = false
			}
		} else {
			tmp = string(s[i]) + tmp
		}
	}

	ans += tmp
	if ans < t {
		fmt.Println(ans)
	} else {
		fmt.Println("No such string")
	}
}
