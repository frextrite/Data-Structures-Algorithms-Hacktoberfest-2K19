/* 
 Example program to reach from a starting given location to a final given destination
 in a nXm matrix that is also given.
 In the matrix, 1's specify a path that you can use from traversing
*/
#include <iostream>
#include <string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

//Class to encapsulate the coordinates and the minimum distance to reach from starting coordinates to this coordinate
class path
{
    public:
    int x;
    int y;
    int dist;
};

void bfs(vector<vector<int>> &matrix, int startx,int starty,int endx,int endy,int n,int m)
{
    //Object of the class to have the initial starting node
    path p1;
    p1.x=startx;
    p1.y=starty;
    p1.dist=0;
    //Using queue because BFS uses queue
    queue<path> q;
    q.push(p1);
    //Visited array is used to keep a track of the coordinates which have already been encountered
    vector<vector<int>>visited(n ,vector<int>(m,0));
    
    path d;
    int flag=0,min_path=100;
    
    while(!q.empty())
    {
        d=q.front();
        q.pop();
        //checking if we have reached the final destination
        if(d.x==endx && d.y==endy)
        {
            flag=1;
            if(d.dist < min_path)
            {
                min_path=d.dist;
            }
        }
        else
        {
            path p2;
            p2.dist=d.dist+1;
            //Checking if the box below is in the matrix, has a path and has not been traversed till now.
            if(((d.x+1)<n)&&(matrix[d.x+1][d.y]==1) && visited[d.x+1][d.y]==0)
            {
                p2.x=d.x+1;
                p2.y=d.y;
                q.push(p2);
                visited[d.x+1][d.y]=1;
            }
            //Checking if the box above is in the matrix, has a path and has not been traversed till now.
            if(((d.x-1)>=0)&&(matrix[d.x-1][d.y]==1) && visited[d.x-1][d.y]==0)
            {
                p2.x=d.x-1;
                p2.y=d.y;
                q.push(p2);
                visited[d.x-1][d.y]=1;
            }
            //Checking if the box on the right is in the matrix, has a path and has not been traversed till now.
            if(((d.y+1)<m)&&(matrix[d.x][d.y+1]==1) && visited[d.x][d.y+1]==0)
            {
                p2.x=d.x;
                p2.y=d.y+1;
                q.push(p2);
                visited[d.x][d.y+1]=1;
            }
            //Checking if the box on the left is in the matrix, has a path and has not been traversed till now.            
            if(((d.y-1)>=0)&&(matrix[d.x][d.y-1]==1)&& visited[d.x][d.y-1]==0)
            {
                p2.x=d.x;
                p2.y=d.y-1;
                q.push(p2);
                visited[d.x][d.y-1]=1;
            }
        }
    }
    //If we were able to find a path then print the Minimum distance to reach there
    if(flag==1)
    {
        cout<<"Minimum distance="<<min_path<<endl;
    }
    else
    {
        cout<<"Not possible to reach"<<endl;
    }
}

void dfs(vector<vector<int>> &matrix, int startx,int starty,int endx,int endy,int n,int m)
{
    //Object of the class to have the initial starting node
    path p1;
    p1.x=startx;
    p1.y=starty;
    p1.dist=0;
    //Using stack because DFS uses stack
    stack<path> st;
    st.push(p1);
    //Visited array is used to keep a track of the coordinates which have already been encountered
    vector<vector<int>>visited(n ,vector<int>(m,0));
    
    path d;
    int flag=0,min_path=100;
    
    while(!st.empty())
    {
        d=st.top();
        st.pop();
        //checking if we have reached the final destination
        if(d.x==endx && d.y==endy)
        {
            flag=1;
            if(d.dist < min_path)
            {
                min_path=d.dist;
            }
        }
        else
        {
            path p2;
            p2.dist=d.dist+1;
            //Checking if the box below is in the matrix, has a path and has not been traversed till now.
            if(((d.x+1)<n)&&(matrix[d.x+1][d.y]==1) && visited[d.x+1][d.y]==0)
            {
                p2.x=d.x+1;
                p2.y=d.y;
                st.push(p2);
                visited[d.x+1][d.y]=1;
            }
            //Checking if the box above is in the matrix, has a path and has not been traversed till now.
            if(((d.x-1)>=0)&&(matrix[d.x-1][d.y]==1) && visited[d.x-1][d.y]==0)
            {
                p2.x=d.x-1;
                p2.y=d.y;
                st.push(p2);
                visited[d.x-1][d.y]=1;
            }
            //Checking if the box on the right is in the matrix, has a path and has not been traversed till now.
            if(((d.y+1)<m)&&(matrix[d.x][d.y+1]==1) && visited[d.x][d.y+1]==0)
            {
                p2.x=d.x;
                p2.y=d.y+1;
                st.push(p2);
                visited[d.x][d.y+1]=1;
            }
            //Checking if the box on the left is in the matrix, has a path and has not been traversed till now.            
            if(((d.y-1)>=0)&&(matrix[d.x][d.y-1]==1)&& visited[d.x][d.y-1]==0)
            {
                p2.x=d.x;
                p2.y=d.y-1;
                st.push(p2);
                visited[d.x][d.y-1]=1;
            }
        }
    }
    //If we were able to find a path then print the Minimum distance to reach there
    if(flag==1)
    {
        cout<<"Minimum distance="<<min_path<<endl;
    }
    else
    {
        cout<<"Not possible to reach"<<endl;
    }
}


int main()
{
    int startx,starty,endx,endy,i,j,n,m,x;
    vector<vector<int>>matrix;
    // N= number of rows, M=number of columns
    cin>>n>>m;
    //startx and starty define the starting coordinates from the matrix
    cin>>startx;
    cin>>starty;
    //endx and endy define the final destination coordinates from the matrix
    cin>>endx;
    cin>>endy;
    //Taking the matrix as input where 1 deines the places where a path exists
    for(i=0; i<n; i++)
    {
        vector<int>v;
        for(j=0; j<m; j++)
        {
            cin>>x;
            v.push_back(x);
        }
        matrix.push_back(v);
    }
    //bfs implementation
    bfs(matrix, startx, starty, endx, endy,n,m);
    dfs(matrix, startx, starty, endx, endy,n,m);
}

