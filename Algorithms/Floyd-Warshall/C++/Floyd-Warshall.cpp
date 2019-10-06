#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;             // n-> Number of Vertices, m-> Number of unidirectional edges (u->v is not the same as v-> u)
	cin>>n>>m;
	int AdjList[n][n];   // Adjlist-> Adjacency list
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				AdjList[i][j]=(INT_MAX/10);
			}
			else
			{
				AdjList[i][i]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		int u,v,x;
		cin>>u>>v>>x;     // edge from u to v (0 based indexing) with edge cost x;
        AdjList[u][v]=x;
	}

	// Floyd-Warshall Algorithm
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				AdjList[i][j]=min(AdjList[i][k]+AdjList[k][j],AdjList[i][j]);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<AdjList[i][j]<<" ";
		}
		cout<<endl;
	}
}
