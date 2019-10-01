#include <iostream>
using namespace std;


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  

        if (arr[mid] == x)
            return mid;


        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);


        return binarySearch(arr, mid + 1, r, x);
    }


    return -1;
}

int main(void)
{
    int arr[50];
    int x,len;
    cout<<"Enter length of list = ";
    cin>>len;
    cout<<"Enter array elements\n";
    for(int i = 0; i < len; i++){
        cin>>arr[i];
    }
    cout<<"Enter element you want to find = ";
    cin>>x;

    int result = binarySearch(arr, 0, len, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
