package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
    )

const c_max = 1e5 + 1

func main() {
    var n int
    fmt.Scanf("%d\n", &n)

    bs := bufio.NewScanner(os.Stdin)
    bs.Split(bufio.ScanWords)
    nums := make([]int, c_max, c_max)
    mmax := 0
    for i := 0; i < n; i++ {
        bs.Scan()
        an, _ := strconv.Atoi(bs.Text())
        nums[an] += 1
        if mmax < an {
            mmax = an
        }
    }

    dp := make([]uint64, c_max, c_max)
    dp[1] = uint64(nums[1])

    // dp[i] = max(dp[i-1], dp[i-2] + nums[i]*i)
    for i := 2; i <= mmax; i++ {
        dp[i] = dp[i-1]
        if dp[i] < dp[i-2] + uint64(nums[i]) * uint64(i) {
            dp[i] = dp[i-2] + uint64(nums[i]) * uint64(i)
        }
    }

    fmt.Println(dp[mmax])
}
