#include <iostream>
#include <cmath>
using namespace std;
bool canplace(int mat[100][100],int i,int j,int num,int n){
    //check in col and row
    for(int x=0;x<n;x++){
        if(mat[x][j]==num || mat[i][x]==num)
            return false;
    }
    //check in sub grid
    int rn=sqrt(n);
    int sx=(i/rn)*rn;
    int sy=(j/rn)*rn;
    for(int x=sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(mat[x][y]==num)
                return false;
        }
    }
    return true;
}
bool solve_sudoku(int mat[100][100],int i,int j,int n){
    //Base case
    if(i==n){
        //print the solution
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl; 
        }
        return true;
    }
    //Row end case
    if(j==n)
        return solve_sudoku(mat,i+1,0,n);
    //skip pre-filled numbers
    if(mat[i][j]!=0)
        return solve_sudoku(mat,i,j+1,n);
    //Recursive case
    //Fill the current cell with possible solutions
    for(int num=1;num<=n;num++){
        if(canplace(mat,i,j,num,n)){
            mat[i][j]=num;
            bool ans=solve_sudoku(mat,i,j+1,n);
            if(ans){
                return true;
            }
        }
    }
    //Backtrack
    mat[i][j]=0;
    return false;
}
int main() {
    int n;
    cin>>n;
    int mat[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    bool ans=solve_sudoku(mat,0,0,n);
    if(!ans){
        cout<<"could not solve"<<endl;
    }
    return 0;
}
