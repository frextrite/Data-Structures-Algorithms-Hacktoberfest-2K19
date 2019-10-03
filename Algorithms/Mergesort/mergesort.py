#!/usr/bin/env python3

def mergesort(unsorted_list):
    n = len(unsorted_list)
    if n > 1:
        m = n // 2
        left = unsorted_list[:m]
        right = unsorted_list[m:]
        mergesort(left)
        mergesort(right)
        merge(unsorted_list, left, right)

def merge(original, left, right):
    i = j = k = 0
    nleft = len(left)
    nright = len(right)
    while i < nleft and j < nright:
        if left[i] < right[j]:
            original[k] = left[i]
            i += 1
        else:
            original[k] = right[j]
            j += 1
        k += 1
    while i < nleft:
        original[k] = left[i]
        i += 1
        k += 1
    while j < nright:
        original[k] = right[j]
        j += 1
        k += 1

if __name__ == '__main__':
    example_list = [-1, 1, 1, 0, -2, 199, 204, 1000, -400, 6]
    print(example_list)
    mergesort(example_list)
    print(example_list)
