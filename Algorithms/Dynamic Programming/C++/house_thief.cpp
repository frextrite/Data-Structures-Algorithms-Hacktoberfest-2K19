/*A thief wants to loot houses and knows the amount of money in each house.
He cannot loot two consecutive houses.The following program returns the maximum amount of money he can loot.*/
//Time complexity: O(n^2); Constraints: 1 <= n <= 10^4
#include <bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n){
    int i;
    int arr2[n+3];
    if(n<3){
        if(n==1){
            return arr[0];  
        }else{
            return max(arr[0],arr[1]);
        }
    }
    arr2[0]=arr[0];
    arr2[1]=arr[1];
    for(i=2;i<n;i++){
        arr2[i]=arr[i];
        arr2[i]+=*max_element(arr2,arr2+i-1);
    }return *max_element(arr2,arr2+n);
}

/* Driver program to test above functions */
int main(){
    int arr1[] = {5, 5, 10, 100, 10, 5};
    cout<<getMaxMoney(arr1,6)<<endl;
    return 0;
}