#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) //Binary Search function to find element x in array arr[]
{
    if (r >= l) {
        int mid = l + (r - l) / 2; //selection of mid element
        return (arr[mid]==x?mid:arr[mid]>x?binarySearch(arr, l, mid - 1, x):binarySearch(arr, mid + 1, r, x));
    }
    return -1;
}
//Main function
int main(void)
{
    int arr[50];
    int x,len;//len stores the number of elements to be given as input
    cout<<"Enter length of list = ";
    cin>>len;
    cout<<"Enter array elements\n";
    for(int i = 0; i < len; i++)//Taking array input
    {
        cin>>arr[i];
    }
    cout<<"Enter element you want to find = ";
    cin>>x;

    int result = binarySearch(arr, 0, len, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
    return 0;
}
