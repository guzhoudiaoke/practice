package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

func main() {
	var n, w int
	fmt.Scan(&n, &w)

	an := make([]int, n*2, n*2)
	bs := bufio.NewScanner(os.Stdin)
	bs.Split(bufio.ScanWords)

	for i := 0; i < 2*n; i++ {
		bs.Scan()
		an[i], _ = strconv.Atoi(bs.Text())
	}

	sort.Sort(sort.IntSlice(an))

	var each float32
	each = float32(an[0])
	if float32(an[n]) < each*2 {
		each = float32(an[n]) / 2
	}
	ans := each * 3 * float32(n)
	if ans > float32(w) {
		ans = float32(w)
	}
	fmt.Println(ans)
}
