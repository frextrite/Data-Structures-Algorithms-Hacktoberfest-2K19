#!/usr/bin/env python3

def quicksort(unsorted_list):
    """
    T(n) = max{T(r - 1) + T(n - r) + O(n)} 
        r: rank of pivot
        worst case => O(n^2) 
        avg case => O(c*nlogn)
    """
    if unsorted_list == None:
        raise Exception('NoneType')
    n = len(unsorted_list)
    if n < 2:
        return unsorted_list
    pivot = unsorted_list[0]
    left = list(filter(lambda x : x < pivot, unsorted_list[1:]))
    right = list(filter(lambda x : x >= pivot, unsorted_list[1:]))
    return quicksort(left) + [pivot] + quicksort(right)

if __name__ == '__main__':
    example_list = [-1, 1, 1, -2, -1, -9999, 0, 10000]
    print(quicksort(example_list))

