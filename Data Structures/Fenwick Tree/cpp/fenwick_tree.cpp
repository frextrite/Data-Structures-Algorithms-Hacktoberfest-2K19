/*
    Fenwick Tree implementation in C++
    - calculates sum of elements of array with range [start,end] in O(log n)
    - updates an element of the array in O(log n)
    - can be constructed in O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int size;
    vector<int> fenwickArr; // Fenwick Tree array is 1-based indexed

    FenwickTree(int size) {
        this->size = size;
        fenwickArr.assign(size+1, 0);
    }

    FenwickTree(vector<int> arr) {
        FenwickTree(arr.size()+1);
        for (int i = 0; i < arr.size()+1; i++) {
            add(i, arr[i]);
        }
    }

    // calculate sum of elements of array A with range [0, end]
    int sum(int end) {
        end += 1;   // Fenwick Tree array is 1-based indexed
        int result = 0;
        for (; end > 0; end-=end&(-end)) {
            result += fenwickArr[end];
        }
        return result;
    }

    // calculate sum of elements of array A with range [start, end]
    int sum(int start, int end) {
        return sum(end) - sum(start-1);
    }

    // add val to arr[idx]
    void add(int idx, int val) {
        idx += 1;   // Fenwick Tree array is 1-based indexed
        for (; idx <= size; idx += idx&(-idx)) {
            fenwickArr[idx] += val;
        }
    }
};

int main() {
    // create Fenwick Tree with array A of size 10
    // A = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    FenwickTree tree = FenwickTree(10);

    // add 2 to A[1]
    // A = [0, 2, 0, 0, 0, 0, 0, 0, 0, 0]
    tree.add(1, 2);

    // print sum of elements of array A[0, 5]
    printf("%d\n", tree.sum(5));    // 2

    // add 5 to A[9]
    // A = [0, 2, 0, 0, 0, 0, 0, 0, 0, 5]
    tree.add(9, 5);

    // print sum of elements of array A[0, 9]
    printf("%d\n", tree.sum(9));    // 7
    // print sum of elements of array A[7, 9]
    printf("%d\n", tree.sum(7, 9)); // 5

    // add 1 to A[7]
    // A = [0, 2, 0, 0, 0, 0, 0, 1, 0, 5]
    tree.add(7, 1);
    // add 2 to A[8]
    // A = [0, 2, 0, 0, 0, 0, 0, 1, 2, 5]
    tree.add(8, 2);
    // add 5 to A[9]
    // A = [0, 2, 0, 0, 0, 0, 0, 1, 2, 8]
    tree.add(9, 3);

    // print sum of elements of array A[0, 9]
    printf("%d\n", tree.sum(9));    // 13
    // print sum of elements of array A[0, 9]
    printf("%d\n", tree.sum(0, 9)); // 13
    // print sum of elements of array A[7, 9]
    printf("%d\n", tree.sum(7, 9)); // 11
    // print sum of elements of array A[8, 9]
    printf("%d\n", tree.sum(8, 9)); // 10

    return 0;
}