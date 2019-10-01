#include <bits/stdc++.h> 
using namespace std; 
  
int ternarySearch(int l, int r, int key, vector <int> arr) 
{ 
    if (l < r) 
    { 
   
        int mid1 = l + (r - l) / 3; 
        int mid2 = r - (r - l) / 3; 

        if (ar[mid1] == key)  
            return mid1; 

        if (ar[mid2] == key) 
            return mid2;  
   
        if (key < ar[mid1]) 
            return ternarySearch(l, mid1 - 1, key, ar); 
        
	else if (key > ar[mid2])  
            return ternarySearch(mid2 + 1, r, key, ar); 
        
	else
            return ternarySearch(mid1 + 1, mid2 - 1, key, ar); 
    } 

    return -1; 
} 
  
// Driver code 

int main() 
{ 
    vector <int> arr;
    int size;
    
    cout << "Enter size of array -> ";
    cin >> size;
    
    for(int i = 0; i < size; i++)
    {
	    cin >> arr[i];
    }

    sort(arr.begin(),arr.end());

    int key;
    cout << "Enter key to be searched -> ";
    cin >> key;

    int ind = ternarySearch(0, size-1, key, arr);

    if(ind != -1)
	    cout << "Key found at index -> " << ind << "\n";
    else
	    cout << "Sorry key not found !\n";
    return 0;

} 
