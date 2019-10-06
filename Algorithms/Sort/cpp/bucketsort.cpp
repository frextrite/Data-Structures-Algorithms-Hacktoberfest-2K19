/* 
implementation of bucket sort 
 */


#include<bits/stdc++.h>
#include <vector>
using namespace std;
void sort(float arr[], int n) // sort function
{
    vector<float> b[n];
    
    for (int i=0; i<n; i++)
    {
       int x = n*arr[i];
       b[x].push_back(arr[i]);
    }
 
    for (int i=0; i<n; i++)
       sort(b[i].begin(), b[i].end());
 
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
          arr[index++] = b[i][j];
}
 
int main()
{ 
    int n;
    cout<<"how many number you want to enter\n";
    cin>>n;
    float arr[n];
    cout<<"enter the elements\n";
    for (int i=0; i<n; i++)
    cin>>arr[i];
    sort(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}