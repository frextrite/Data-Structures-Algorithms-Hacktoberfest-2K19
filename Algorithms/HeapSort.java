import java.util.Arrays;

public class HeapSort {

    public void sort(int arrA[]) {
        int size = arrA.length;

        // Build heap
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(arrA, size, i);

        // One by one extract (Max) an element from heap and
        // replace it with the last element in the array
        for (int i=size-1; i>=0; i--) {

            //arrA[0] is a root of the heap and is the max element in heap
            int x = arrA[0];
            arrA[0] = arrA[i];
            arrA[i] = x;

            // call max heapify on the reduced heap
            heapify(arrA, i, 0);
        }
    }

    // To heapify a subtree with node i
    void heapify(int arrA[], int heapSize, int i) {
        int largest = i; // Initialize largest as root
        int leftChildIdx  = 2*i + 1; // left = 2*i + 1
        int rightChildIdx  = 2*i + 2; // right = 2*i + 2

        // If left child is larger than root
        if (leftChildIdx  < heapSize && arrA[leftChildIdx ] > arrA[largest])
            largest = leftChildIdx ;

        // If right child is larger than largest so far
        if (rightChildIdx  < heapSize && arrA[rightChildIdx ] > arrA[largest])
            largest = rightChildIdx ;

        // If largest is not root
        if (largest != i) {
            int swap = arrA[i];
            arrA[i] = arrA[largest];
            arrA[largest] = swap;

            // Recursive call to  heapify the sub-tree
            heapify(arrA, heapSize, largest);
        }
    }

    public static void main(String args[]) {
        int arrA[] = {9, 10, 5, 3, 1, 2, 6};

        System.out.println("Original array is: " + Arrays.toString(arrA));
        HeapSort heapSort = new HeapSort();
        heapSort.sort(arrA);

        System.out.println("Sorted array is (Heap Sort): " + Arrays.toString(arrA));
    }
}