#include <bits/stdc++.h>
using namespace std;
//This is Kadane's Algorithm for maximum Subarray Sum
int maxSubArraySum(int a[], int array_size)
{
    int global_max_sum = INT_MIN, local_max_sum = 0;

    for (int i = 0; i < array_size; i++)
    {
        local_max_sum = local_max_sum + a[i];
        if (global_max_sum < local_max_sum )
            global_max_sum = local_max_sum;

        if (local_max_sum < 0)
            local_max_sum = 0;
    }
    return global_max_sum;
}

int main() {

   int a[] = {-1,-2,-5,1,4,6,-5,-3,11};
    int array_size = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, array_size);
    cout << "Maximum contiguous subarray sum is " << max_sum;
    return 0;
}