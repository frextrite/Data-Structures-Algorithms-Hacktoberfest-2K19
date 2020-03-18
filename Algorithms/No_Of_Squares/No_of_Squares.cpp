#include<iostream> 
using namespace std; 
int countSquares(int m, int n) 
{ 
if (m < n) 
    swap(n, m); 
    int c= n * (n + 1) * (2 * n + 1) /  
     6 + (m - n) * n *(n + 1) / 2; 
    return c;
} 
int main() 
{ 
int m = 4, n = 3; //m is the no. rows and n the no. of column
cout << "The No: of squares in the "<<
     m<<"X"<<n<<" "<<"matrix is: "
     << countSquares(m, n); 
} 
