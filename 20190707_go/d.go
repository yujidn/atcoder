package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)
	dam := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &dam[i])
	}
	yama := make([]int, n)
	yama[0] = 0

	for i := 0; i < n; i++ {
		if i%2 == 0 {
			yama[0] += dam[i]
		} else {
			yama[0] -= dam[i]
		}
	}

	for i := 1; i < n; i++ {
		yama[i] = (dam[i-1] - yama[i-1]/2) * 2
	}

	for i := 0; i < n; i++ {
		fmt.Printf("%d ", yama[i])
	}

	fmt.Println()

}
