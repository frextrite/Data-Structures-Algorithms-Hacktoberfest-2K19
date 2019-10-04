/*A child is running up a staircase with n steps and can hop either 1 step,2 steps or 3 steps at a time.
Implementing a recursive method to count total number of ways the child can run up the stairs.*/
//Time complexity: O(n); Constraints: n <= 70
#include<bits/stdc++.h>
using namespace std;

long staircase(int n){
    int i;
    long arr[n+4];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    if(n<3){
        return arr[n];
    }
    for(i=3;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
    }return arr[n];
}

/* Driver program to test above functions */
int main(){
    cout<<staircase(4)<<endl;
    return 0;
}