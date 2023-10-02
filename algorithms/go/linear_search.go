// Linear Search
// Time Complexity: O(n)
/*
Here in this code we first define a function called
linearSort which takes two arguments, an array and a search value.
Then we loop through the array and check
if the search value is equal to the current value in the array.
If it is, we return the index of that value.
If we don’t find the value, we return -1.
*/
package main

import "fmt"

func linearSort(arr []int, s int) int {
	for index, value := range arr {
		if s == value {
			return index
		}
	}

	return -1
}

func main() {
	var n = []int{9, 1, 33, 21, 78, 42, 4}

	fmt.Println(linearSort(n, 78))
}
