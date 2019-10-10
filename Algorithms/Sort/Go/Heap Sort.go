//https://gostudent.github.io/Letsgo/implementation-of-heap-sort-in-GO
package main

import "fmt"
import "math/rand"
import "time"

type MaxHeap struct {
	slice    []int
	heapSize int
}

func BuildMaxHeap(slice []int) MaxHeap {
	h := MaxHeap{slice: slice, heapSize: len(slice)}
	for i := len(slice) / 2; i >= 0; i-- {
		h.MaxHeapify(i)
	}
	return h
}

func (h MaxHeap) MaxHeapify(i int) {
	l, r := 2*i+1, 2*i+2
	max := i

	if l < h.size() && h.slice[l] > h.slice[max] {
		max = l
	}
	if r < h.size() && h.slice[r] > h.slice[max] {
		max = r
	}
	if max != i {
		h.slice[i], h.slice[max] = h.slice[max], h.slice[i]
		h.MaxHeapify(max)
	}
}

func (h MaxHeap) size() int { return h.heapSize } 

func heapSort(slice []int) []int {
	h := BuildMaxHeap(slice)
	for i := len(h.slice) - 1; i >= 1; i-- {
		h.slice[0], h.slice[i] = h.slice[i], h.slice[0]
		h.heapSize--
		h.MaxHeapify(0)
		if i == len(h.slice)-1 || i == len(h.slice)-3 || i == len(h.slice)-5 {
			element := (i - len(h.slice)) * -1
			fmt.Println("Heap after removing ", element, " elements")
			fmt.Println(h.slice)

		}
	}
	return h.slice
}

func main() {
	s1 := rand.NewSource(time.Now().UnixNano())
	r1 := rand.New(s1)
	s := make([]int, 20)
	for index, _ := range s {
		s[index] = r1.Intn(400)
	}
	fmt.Println("Randomly generated array:")
	fmt.Println(s)
	h := BuildMaxHeap(s)
	fmt.Println("\nInital Heap: ")
	fmt.Println(h.slice, "\n")

	s = heapSort(s)
	fmt.Println("\nFinal List:")
	fmt.Println(s)
}
