package main
import "fmt"

const MAX_LEN int = 64;

func main() {
	var n, k int
	var scores[MAX_LEN] int

	fmt.Scanf("%d %d\n", &n, &k)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &scores[i])
	}

	var r int
	for r = 0; r < n; r++ {
		if scores[r] <= 0 || scores[r] < scores[k-1] {
			break
		}
	}

	fmt.Printf("%d\n", r)
}
