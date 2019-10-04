#include <algorithm>
#include <cstdio>
#define INF 1000000000
using namespace std;

//All Pairs Shortest Paths  
int main(){
	int V, E, v, u, w, i, j, k;
	scanf("%d %d", &V, &E);
	int matrizAdj[V][V];
	//initializing matriz with zero value
	for(i=0; i < V; i++){
		for(int j=0; j< V; j++)
			matrizAdj[i][j] = INF;
		matrizAdj[i][i] = 0;
	}
	
	for(i = 0; i<E; i++){
		//reading links between vertices of a graph and their weights
		scanf("%d %d %d", &u, &v, &w);
		matrizAdj[u][v] = matrizAdj[v][u] = w;
		
	}
	
	//Floyd-Warshall algorithm
	for(k = 0; k<V; k++)
		for(i = 0; i< V; i++)
			for(j = 0; j<V; j++)
				matrizAdj[i][j] = min(matrizAdj[i][j], matrizAdj[i][k] + matrizAdj[k][j]); 
	
	for(i=0; i < V; i++){
		for(j=0; j< V; j++)
			//print all pairs shortest paths of a graph
			printf("APSP(%d, %d) = %d\n", i, j, matrizAdj[i][j]);
	}
	return 0;
}
