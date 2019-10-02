#include<iostream>
using namespace std;

int main(){
   int number[10] = {12,4,2,55,21,88,3,14,9,11};
   int size = sizeof(number)/sizeof(number[0]);

for(int j = 0; j < (size -1) ; j++ )
   for( int i =0; i< (size-1) - j ; i++){
     if(number[i] > number[i+1]){
       int temp = number[i+1];
       number[i+1] = number[i];
       number[i] = temp;
     }

   }

   for(int i = 0;i<size; i++){
     cout<<number[i] << " ";
   }

}
