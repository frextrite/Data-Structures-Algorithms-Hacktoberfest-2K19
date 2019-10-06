package com.example;

import java.util.*;
import java.util.stream.*;

public class BucketSort {
    public static int[] sort(int[] array, int max_val) {
        int[] bucket = new int[max_val + 1];
        int[] sorted_nums = new int[array.length];
        for (int i = 0; i < array.length; i++)
            bucket[array[i]]++;
        int pos = 0;
        for (int i = 0; i < bucket.length; i++)
            for (int j = 0; j < bucket[i]; j++)
                sorted_nums[pos++] = i;
        return sorted_nums;
    }

    public static void main(String args[]) {
        int data[] = {7, 3, 2, 1, 0, 45};
        int max_val = Arrays.stream(data).max().getAsInt();

        System.out.println("Original Array:");
        System.out.println(Arrays.toString(data));

        data = sort(data, max_val);
        System.out.println("Sorted Array:");
        System.out.println(Arrays.toString(data));
    }
}