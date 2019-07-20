package main

import "fmt"

func main() {
	var (
		n int
		a int
		b int
	)
	fmt.Scanf("%d %d %d", &n, &a, &b)
	var bus = a * n
	var taxi = b

	var result = bus
	if bus > taxi {
		result = taxi
	}

	fmt.Println(result)

}
