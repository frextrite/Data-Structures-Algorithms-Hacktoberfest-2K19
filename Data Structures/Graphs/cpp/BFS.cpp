#include <iostream>
#include <queue>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int i = 0; i<n ;i++){
            if(visited[i]){
                continue;
            }
            if(edges[x][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}




int main() {
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for( int i = 0; i<n; i++){
        edges[i] = new int[n];
        for( int j = 0; j<n ;j++){
            edges[i][j] = 0;
        }
    }

    bool* visited  = new bool[n];
    for(int i =0 ; i < n; i++){
        visited[i] = false;
    }

    for( int i = 0 ; i<e ; i++){
        int f, s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    printBFS(edges, n, 0, visited);

  return 0;
}
