//       Generating minimum spanning tree using Prim's Algorithm
//       Complexity - O(Elog(V))


#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair

int v,e;   //v represents number of vertices  
           // e represents number of edges


//Finding minimum key
int minKey(int key[], bool mst[])
{
	int vertex;
	int mini = INT_MAX;
	for(int i = 0; i<v; i++)
	{
		if(key[i]<mini && !mst[i])
		{
			mini = key[i];
			vertex = i;
		}
	}
	return vertex;
}

//Finding Minimum Spanning Tree
void primMST( vector<pair<int,int>> adj[])
{
   int parent[v];    // parent array to store parent of an node
   int key[v];       //key array containing  weight
   bool mst[v];      //boolean mst array to check whether it is included in mst or not

   //Initialising value of all key to be MAXINT && boolean mst to be false
   for(int i = 0;i < v; i++)
   {
   	 key[i]=INT_MAX; 
   	 mst[i]=false;
   }

   //Start traversal with 0 as source vertex
   parent[0]=-1;
   key[0]=0;

   //Since  minimum spanning tree includes v-1 vertices
   for(int i = 0; i < v-1; i++)
   {
   	 int ver = minKey(key, mst);  //Finding minimum key

   	 mst[ver]=true;   //include above vertex in mst

   	 for(int i = 0; i < adj[ver].size(); i++)    //updating distances of adjacent nodes to above vertex 
   	 {
   	 	if( !mst[adj[ver][i].ff] && adj[ver][i].ss < key[adj[ver][i].ff] )
   	 	{
   	 		parent[adj[ver][i].ff]=ver;
   	 		key[adj[ver][i].ff] = adj[ver][i].ss;
   	 	}
   	 }
   }
   
   //Printing MST
   cout<<"Prim's Minimum Spanning Tree of given graph is "<<endl;
   cout<<"Parent"<<" "<<"Child"<<" "<<"Weight"<<endl;
   for(int i = 1; i < v; i++)
   {
   	 cout<<"    "<<parent[i]<<"    "<<i<<"    "<<key[i]<<endl;
   }
}


int main() 
{ 
   //v represents number of vertices
   //e represents number of edges
   cout<<"Enter number of vertices and edges respectively"<<endl;
   cin>>v>>e;	

   //adjacency list is used to store vertex and their respective weights
   vector<pair<int,int>> adj[v];
   cout<<"Enter source and destination vertex with their weights "<<endl;
   for(int i = 0;i < e; i++)
   {
        //a represents vertex 1
        //b represents vertex 2
        //w represents weight of edge between a and b

   	  int a,b,w; 
        cin>>a>>b>>w;
   	  adj[a].pb(mp(b,w));
   	  adj[b].pb(mp(a,w));
   }
   //Generating minimum spanning tree using Prim's Algorithm
   // '0' is assumed to be source vertex
   primMST(adj);
}



