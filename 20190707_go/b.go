package main

import (
	"fmt"
	"math"
)

func main() {
	var (
		n int
		d int
	)

	fmt.Scanf("%d %d", &n, &d)

	xd := make([][]float64, n)

	for i := 0; i < n; i++ {
		xd[i] = make([]float64, d)
		for j := 0; j < d; j++ {
			var t float64
			fmt.Scanf("%f", &t)
			xd[i][j] = t
		}
	}

	count := 0
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			var dist float64
			dist = 0.0
			for k := 0; k < d; k++ {
				temp := xd[i][k] - xd[j][k]
				dist += temp * temp
			}
			dist = math.Sqrt(dist)
			check := float64(int(dist))
			if int(check/dist) == 1 {
				count++
			}
			// fmt.Printf("%d %d %f\n", i, j, dist)
		}
	}
	fmt.Println(count)
}
