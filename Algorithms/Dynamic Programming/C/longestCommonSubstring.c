#include<stdio.h> 
#include<string.h>  
  
int LCSubStr(char *X, char *Y, int m, int n) 
{ 
    int LCSuff[m+1][n+1]; 
    int result = 0;
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                LCSuff[i][j] = LCSuff[i-1][j-1] + 1; 
                result = result >  LCSuff[i][j] ? result : LCSuff[i][j]; 
            } 
            else LCSuff[i][j] = 0; 
        } 
    } 
    return result; 
} 
  
/* Driver program*/
int main() 
{ 
    char X[] = "abcdef.org"; 
    char Y[] = "ababcdh.com"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    printf("Length of Longest Common Substring is %d \n", LCSubStr(X, Y, m, n)); 
    return 0; 
}
